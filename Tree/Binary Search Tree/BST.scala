class BST[K, V](implicit ord: Ordering[K]) extends SymbolTable[K, V] {
  // Internal representation
  private sealed trait BTree[K, V]
  private case object Tip extends BTree[K, V]
  private case class Branch[K, V](key: K, elem: V,
                                  left: BTree[K, V], right: BTree[K, V]) extends BTree[K, V]

  private var tree: BTree[K, V] = Tip
  override def isEmpty: Boolean = tree match {
    case Tip => true
    case _ => false
  }

  private def count(t: BTree[K, V]): Int = t match {
    case Tip => 0
    case Branch(_, _, l, r) => 1 + count(l) + count(r)
  }
  def size: Int = count(tree)

  @annotation.tailrec
  private def search(key: K, t: BTree[K, V]): Option[V] = t match {
    case Tip => None
    case Branch(k, v, _, _) if (ord.equiv(key, k)) => Some(v)
    case Branch(k, _, l, _) if (ord.lt(key, k)) => search(key, l)
    case Branch(k, _, _, r)  => search(key, r)
  }
  def apply(k: K): Option[V] = search(k, tree)

  @annotation.tailrec
  private def findMin(t: BTree[K, V]): Option[(K, V)] = t match {
    case Tip => None
    case Branch(k, v, Tip, _) => Some((k, v))
    case Branch(k, v, l, _) => findMin(l)
  }
  def findMin: Option[(K, V)] = findMin(tree)

  private def deleteMin(t: BTree[K, V]): BTree[K, V] = t match {
    case Tip => Tip
    case Branch(k, v, Tip, Tip) => Tip
    case Branch(k, v, Tip, r) => r
    case Branch(k, v, l, r) => Branch(k, v, deleteMin(l), r)
  }
  def deleteMin(): Unit = tree = deleteMin(tree)

  def clear(): Unit = tree = Tip

  private def put(key: K, value: V, t: BTree[K, V]): BTree[K, V] = t match {
    case Tip => Branch(key, value, Tip, Tip)
    case Branch(k, v, l, r) if (ord.equiv(k, key)) => Branch(k, value, l, r)
    case Branch(k, v, l, r) if (ord.lt(key, k)) =>
      Branch(k, v, put(key, value, l), r)
    case Branch(k, v, l, r) => Branch(k, v, l, put(key, value, r))
  }
  def put(key: K, value: V): Unit = tree = put(key, value, tree)

  private def foreach(f: ((K, V)) => Unit, t: BTree[K, V]): Unit = t match {
    case Tip => ()
    case Branch(k, v, l, r) =>
      foreach(f, l)
      f((k, v))
      foreach(f, r)
  }
  def foreach(f: ((K, V)) => Unit): Unit = foreach(f, tree)

  private def delete(key: K, t: BTree[K, V]): BTree[K, V] = t match {
    case Tip => t  // Wasn't found
    case Branch(k, _, Tip, r) if (ord.equiv(key, k)) => r // Found it, is min
    case Branch(k, _, l, Tip) if (ord.equiv(key, k)) => l // Found it, easy to delete
    case Branch(k, _, l, r) if (ord.equiv(key, k)) => // Found it; tricky case
      val minVal = findMin(r).get  // Can't be None
      Branch(minVal._1, minVal._2, l, deleteMin(r))  // Swap with min, delete min
    case Branch(k, v, l, r) if (ord.lt(key, k)) => Branch(k, v, delete(key, l), r)
    case Branch(k, v, l, r) => Branch(k, v, l, delete(key, r))
  }
  def delete(k: K): Unit = tree = delete(k, tree)

  private def stringify(t: BTree[K, V]): String = t match {
    case Tip => ""
    case Branch(k, v, Tip, Tip) => s"$k -> $v"
    case Branch(k, v, Tip, r) => s"$k -> $v, " + stringify(r)
    case Branch(k, v, l, Tip) => stringify(l) + s", $k -> $v"
    case Branch(k, v, l, r) => stringify(l) + s", $k -> $v, " + stringify(r)
  }

  override def toString: String = "BST(" + stringify(tree) + ")"
}

object BST {
  def empty[K, V](implicit ord: Ordering[K]): BST[K, V] = new BST[K, V]
  def apply[K, V](args: (K, V)*)(implicit ord: Ordering[K]): BST[K, V] = {
    val e = new BST[K, V]
    for ((k, v) <- args)
      e.put(k, v)
    e
  }
}
