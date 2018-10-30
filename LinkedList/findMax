//pre: list is not null
public E findMax (ListNode<E> list)
{
  E temp = list.getValue();
  if(list.getNext() == null)
    return temp;
  else
  {
    if(temp.compareTo(list.getNext().getValue()) > 0)
    {
      list.getNext().setValue(temp);
      return findMax(list.getNext());
    }
    else
      return findMax(list.getNext());
  }
}
    
