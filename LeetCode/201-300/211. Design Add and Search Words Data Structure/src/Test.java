public class Test {
    public static void main(String[] args) {
        WordDictionary wordDictionary = new WordDictionary();
        wordDictionary.addWord("abc");
        wordDictionary.addWord("abd");
        wordDictionary.addWord("aca");
        System.out.println(wordDictionary.search("..a"));
    }
}
