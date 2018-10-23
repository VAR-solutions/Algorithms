;;; An implementation of heap-2 from this article
;;; http://scholar.colorado.edu/cgi/viewcontent.cgi?article=1000&context=asen_facpapers


(defstruct heap2-element
  ;; doubly linked list structure
  back
  fwd
  ;; data
  (bucket -1 :type integer)
  distance
  (in-S-p nil :type boolean)
  (previous -1 :type integer)		;the index of the graph node
					;that comes before this
					;element on a shortest path
					;from the source
  (this -1 :type integer))		;The index of this element in the graph.


;;; The graph nodes will store their status internaly. Two fields will
;;; be added. One will hold the information of whther the node is in
;;; S, the other will hold a pointer to the heap node representing
;;; this graph node in the heap. If the latter is nil, then the node
;;; is not in the heap.


(defstruct heap2
  buckets				;the array of buckets
  (start -1 :type integer)		;the index of the lowest bucket
  l-min
  l-max
  (beta 0 :type integer))

(defstruct graph-node
  (this -1 :type integer)
  edge-weight)


(defun heap2-insert-head (heap he k)
  (let ((old-head (aref (heap2-buckets heap) k)))
    (when old-head			;inserting into empty list
      (setf (heap2-element-back old-head) he))
    (setf (heap2-element-bucket he) k)
    (setf (heap2-element-fwd he) old-head)
    (setf (aref (heap2-buckets heap) k) he)
    he))


(defun heap2-delete-from-list (heap he)
  "delete the given heap element from the list it is in. Returns the
  modified he."
  (let ((prev (heap2-element-back he))
	(next (heap2-element-fwd he)))
    (when next				;if he is the last element, next is nil
      (setf (heap2-element-back next) prev))
    (if prev				;if he is the first element, prev is nil
      (setf (heap2-element-fwd prev) next)
      (setf (aref (heap2-buckets heap) (heap2-element-bucket he)) next))
    (setf (heap2-element-fwd he) nil)
    (setf (heap2-element-bucket he) -1)
    (setf (heap2-element-back he) nil)
    he))

(defun heap2-update-value (heap he new-distance previous)
  "Update the distance in node v and change the heap
  accordingly. `he` is a heap2-element and might yet have to be added
  to the heap. `previous` is the node that was just added to S and is
  a neighbour of the current node. Uses Alg. 4 from
  http://scholar.colorado.edu/cgi/viewcontent.cgi?article=1000&context=asen_facpapers"
  (let* ((l (heap2-l-min heap))
	 (beta (heap2-beta heap))
	 (k (mod (floor new-distance l) (1+ beta))))
    (setf (heap2-element-distance he) new-distance)
    (setf (heap2-element-previous he) previous)
    (if (>= (heap2-element-bucket he) 0) ;element is in the heap
	(progn
	  (heap2-delete-from-list heap he)
	  (heap2-insert-head heap he k))
	(heap2-insert-head heap he k)))
  nil)

(defun heap2-pop-min (heap)
  "Pop the node to be inserted into S from the heap."
  (let* ((kf (mod (1- (heap2-start heap))
		  (1+ (heap2-beta heap))))
	 (k (do ((kc (mod (heap2-start heap)
			  (1+ (heap2-beta heap)))
		     (mod (1+ kc)
			  (1+ (heap2-beta heap)))))
		((or (= kc kf) (aref (heap2-buckets heap) kc))
		 kc)))
	 (b (aref (heap2-buckets heap) k)))
    (setf (heap2-start heap) k)
    (when b			 ;not empty, b is the head of the list
      (heap2-delete-from-list heap b))))

;;; dijkstra algorithm using heap 2

(defun edge-lengths (graph)
  "get a list of all edge lengths for the given adjancency list
  represented graph."
  (apply #'nconc (map 'list (lambda (neighbours)
			      (mapcar #'graph-node-edge-weight neighbours))
		      graph)))


(defun heap2-dijkstra (graph origin)
  "returns an array of heap2-elements each with a calculated distance
  from the origin and the node that comes on the shortest path before
  the current node. thus they can be used to reconstruct the actual
  shortest path from origin to given graph node in O(edges in path)
  time. `graph` is an array of lists. the elements of each list are
  graph-nodes. `origin is the index denoting the origin vertex in the
  graph adjacency list."
  (let* ((s (make-array (length graph)
			:initial-contents (loop for i below (length graph)
					     collect (make-heap2-element :this i))))
	 (edge-lengths (edge-lengths graph))
	 (l-min (apply #'min edge-lengths))
	 (l-max (apply #'max edge-lengths))
	 (beta (ceiling l-max l-min))
	 (heap (make-heap2 :buckets (make-array (1+ beta) :initial-element nil)
			   :beta beta
			   :l-min l-min
			   :l-max l-max
			   :start 0)))
    (setf (heap2-element-distance (aref s origin)) 0)
    (labels ((get-new-distance-and-ancestor
		 (node neighbour)
	       (let* ((p-he (aref s node))
		      (n-he (aref s (graph-node-this neighbour)))
		      (new-distance
		       (+ (heap2-element-distance p-he)
			  (graph-node-edge-weight neighbour))))
		 (if n-he
		     (let ((distance (heap2-element-distance n-he)))
		       (if distance
			   (if (< new-distance distance)
			       (values new-distance (heap2-element-this p-he))
			       ;; if diatance is nil then it is effectively inf
			       (values distance (heap2-element-previous n-he)))
			   (values new-distance (heap2-element-this p-he))))
		     (values new-distance (heap2-element-this p-he)))))
	     (update-node
		 (node)
	       (mapc (lambda (neighbour)
		       (multiple-value-bind (new-distance previous)
			   (get-new-distance-and-ancestor node neighbour)
			 (when (not (heap2-element-in-s-p
				     (aref s (graph-node-this neighbour))))
			   (heap2-update-value heap (aref s (graph-node-this neighbour))
					       new-distance
					       previous))))
		     (aref graph node))))
      (setf (heap2-element-in-s-p (aref s origin)) t)
      (update-node origin)
      (do ((next-element (heap2-pop-min heap) (heap2-pop-min heap)))
	  ((not next-element) s)
	(setf (heap2-element-in-s-p next-element) t)
	(update-node (heap2-element-this next-element))))))


(defvar test-graph (vector (list (make-graph-node :this 1 :edge-weight 1)
				 (make-graph-node :this 2 :edge-weight 4)
				 (make-graph-node :this 3 :edge-weight 2))
			   (list (make-graph-node :this 2 :edge-weight 3)
				 (make-graph-node :this 3 :edge-weight 3))
			   '()
			   (list (make-graph-node :this 2 :edge-weight 1))
			   (list (make-graph-node :this 0 :edge-weight 5))))


(defvar test-graph2 (vector (list (make-graph-node :this 1 :edge-weight 4)
				  (make-graph-node :this 2 :edge-weight 2.5)
				  (make-graph-node :this 3 :edge-weight 3)
				  (make-graph-node :this 5 :edge-weight 2))
			    (list (make-graph-node :this 0 :edge-weight 1))
			    (list (make-graph-node :this 4 :edge-weight 3.2))
			    (list (make-graph-node :this 1 :edge-weight 1))
			    (list (make-graph-node :this 3 :edge-weight 0.5)
				  (make-graph-node :this 0 :edge-weight 1))
			    (list (make-graph-node :this 3 :edge-weight 0.5))))

(defun heap2-get-shortest-path (s node)
  "s is a vector as returned by heqp2-dijksra, node is an integer
  denoting a node of the graph"
  (labels ((helper (node accum)
	     (let* ((current (aref s node))
		    (previous (heap2-element-previous current))
		    (is-solution (heap2-element-in-s-p current))
		    (current-index (heap2-element-this current)))
	       (cond
		 ((not is-solution) nil)
		 ((= -1 previous) (cons current-index accum))
		 (t (helper previous (cons current-index accum)))))))
    (helper node '())))
