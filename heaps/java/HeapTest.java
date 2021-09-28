public class HeapTest {

	private Heap heap;
	
	@Before
	public void initializeHeap() {
		heap = new Heap(10);
	}
	
	@Test
	public void emptyHeap() {
		assertTrue(heap.isEmpty());
		assertEquals(0, heap.qtd());
	}
	
	@Test
	public void stackFirstElement() {
		heap.stackUp("first");
		
		assertFalse(heap.isEmpty());
		assertEquals(1, heap.qtd());
		assertEquals("first", heap.top());
	}
	
	@Test
	public void stackUpAndUnstack() {
		heap.stackUp("first");
		heap.stackUp("second");
		
		assertEquals(2, heap.qtd());
		assertEquals("second", heap.top());
		
		Object unstacked = heap.unstack();
		
		assertEquals(1, heap.qtd());
		assertEquals("first", heap.top());
		assertEquals("second", unstacked);
	}
	
	@Test(expected = EmptyHeapException.class)
	public void unstackEmptyHeap() {
		heap.unstack();		
	}
	
	@Test
	public void addFullStack() {
		for(int i = 0; i < 10; i++){
			heap.stackUp("elemento " + i);
		}
		
		try {
			heap.stackUp("Booom!!!");
			fail();
		} catch (FullStackException e) {}
	}
}
