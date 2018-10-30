import static org.junit.Assert.assertEquals;

public class CountWordsTest {

	public void testWords() {
		assertEquals(4, CountWords.countWords("There are four words."));
	}
	public void testNumbers() {
		assertEquals(4, CountWords.countWords("There are 4 words."));
	}
	public static void main(String[] args) {
		CountWordsTest t = new CountWordsTest();
		t.testWords();
		t.testNumbers();
	}

}
