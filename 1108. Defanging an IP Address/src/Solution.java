class Solution {
    public String defangIPaddr(String address) {
        char[] arr = address.toCharArray();
        char[] newArr = new char[arr.length + 6];
        int pointer = 0;
        for (int i = 0; i < arr.length; i++) {
            if (arr[i] != '.') {
                newArr[pointer] = arr[i];
                pointer++;
            } else {
                newArr[pointer++] = '[';
                newArr[pointer++] = '.';
                newArr[pointer++] = ']';
            }
        }
        return String.valueOf(newArr);
    }
}