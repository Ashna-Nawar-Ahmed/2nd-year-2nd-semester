package pkg16.pkg02.pkg04.pkg024_offline_9_huffman;
import java.util.Comparator;
import java.util.PriorityQueue;
import java.util.Scanner;
public class Main {
    public static void main(String[] args) {
        Scanner input = new Scanner(System.in);
        System.out.println("Enter a string:");
        int ar[] = new int[300];
        String s = input.next();
        Element e[] = new Element[300];
        for (int i = 0; i < 300; i++) {
            e[i] = new Element();
        }
        for (int i = 0; i < s.length(); i++) {
            char ch = s.charAt(i);
            int val = (int) ch;
            ar[val] = ar[val] + 1;
        }
        int count = 0;
        PriorityQueue<Element> pq = new PriorityQueue<Element>(s.length(), new FrequencyComparator());
        for (int i = 32; i <= 255; i++) {
            if (ar[i] > 0) {
                e[count].c = (char) i;
                e[count].freq = ar[i];
                e[count].left = null;
                e[count].right = null;
                pq.add(e[count]);
                count++;
            }

        }
        Element root = null;
        while (pq.size() > 1) {
            Element first = pq.poll();
            Element second = pq.poll();
            Element sum = new Element();
            sum.val = first.val + second.val;
            sum.left = first;
            sum.right = second;
            sum.c = '-';
            root = sum;
            pq.add(sum);
        }
        System.out.println("Codes will be:");
        encoder(root, "");
        System.out.println("Encoded string is:");
        String code = "";
        for (int i = 0; i < s.length(); i++) {
            char ch = s.charAt(i);
            System.out.print(codes[(int) ch]);
            code = code + codes[(int) ch];
        }
        System.out.println("");
        

    }
    public static String[] codes = new String[300];

    public static void encoder(Element root, String s) {
        if (root.left == null && root.right == null) {
            System.out.println(root.c + ":" + s);
            codes[(int) root.c] = s;
            return;
        }
        encoder(root.left, s + "0");
        encoder(root.right, s + "1");
    }

}

class Element {
    char c;
    int freq = 0, val = 0;
    Element left = null, right = null;
}
class FrequencyComparator implements Comparator<Element> {

    @Override
    public int compare(Element a, Element b) {
        return a.freq - b.freq;
    }
}
