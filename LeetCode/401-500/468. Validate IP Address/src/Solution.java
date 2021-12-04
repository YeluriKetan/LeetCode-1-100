import java.util.Arrays;
import java.util.regex.Pattern;

class Solution {
    public String validIPAddress(String IP) {
        if (IP.contains(":")) {
            return ipv6(IP);
        } else {
            return ipv4(IP);
        }
    }

    private String ipv4(String IP) {
        String[] arr = IP.split("\\.", -1);
        if (arr.length != 4) {
            return "Neither";
        }
        for (int i = 0; i < 4; i++) {
            if (arr[i].length() == 0 | arr[i].length() > 3) {
                return "Neither";
            }
            if (Pattern.compile("(?i)(.*[a-z]+.*|0+\\d+)").matcher(arr[i]).matches()) {
                return "Neither";
            }

            int j = Integer.parseInt(arr[i]);
            if (j < 0 || j > 255) {
                return "Neither";
            }
        }
        return "IPv4";
    }

    private String ipv6(String IP) {
        String[] arr = IP.split(":",-1);
        System.out.println(Arrays.toString(arr));
        if (arr.length != 8) {
            return "Neither";
        }
        for (int i = 0; i < 8; i++) {
            if (!Pattern.compile("(?i)[a-f\\d]{1,4}").matcher(arr[i]).matches()) {
                return "Neither";
            }
        }
        return "IPv6";
    }
}