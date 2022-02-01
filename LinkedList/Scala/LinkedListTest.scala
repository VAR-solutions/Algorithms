package Scala

object LinkedListTest {
	def test(): Boolean = {
		val list = new LinkedList[String]
		list.append("value A")
		list.append("value B")
		list.prepend("value C")
		if (list.length != 3) return false
		if (list.apply(0) != "value C") return false
		if (list.apply(1) != "value A") return false
		if (list.apply(2) != "value B") return false
		if (!list.iterator.hasNext) return false

		list.remove(1)
		list.remove(0)
		if (list.apply(0) != "value B") return false
		if (!list.iterator.hasNext) return false

		list.remove(0)
		if (list.length != 0) return false

		if (list.iterator.hasNext) return false

		true
	}

	def main(args: Array[String]): Unit = {
		println(test())
	}
}
