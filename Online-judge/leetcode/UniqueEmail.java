package Letcode;

import java.util.HashSet;
import java.util.Set;

/**
 * @author Md.Shohag <shohag.fks@gmail.com>
 * Problem : https://leetcode.com/problems/unique-email-addresses
 */

public class UniqueEmail {
    public int numUniqueEmails(String[] emails) {
        Set<String> uniqueEmails = new HashSet<>();
        for(String email: emails) {
            String [] emailInformation = email.split("@");
            String localName = emailInformation[0];
            String domainName = emailInformation[1];
            localName = localName.replace(".", "");
            int findIndex = localName.indexOf('+');
            if (findIndex >= 0) {
                localName = localName.substring(0, findIndex);
            }
            uniqueEmails.add(localName+"@" + domainName);
        }
        return uniqueEmails.size();
    }
    public static void main(String[] args) {
        UniqueEmail email = new UniqueEmail();
        String[] s = {"test.email+alex@leetcode.com", "test.e.mail+bob.cathy@leetcode.com",
                "testemail+david@lee.tcode.com"};
        System.out.println(email.numUniqueEmails(s));
    }
}
