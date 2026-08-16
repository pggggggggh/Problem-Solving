class Solution {
    public ListNode addTwoNumbers(ListNode l1, ListNode l2) {
        ListNode p1 = l1;
        ListNode p2 = l2;
        ListNode pres = null;
        ListNode pnow = null;
        int up = 0;
        while (p1 != null || p2 != null || up != 0) {
            int cal = up;
            if (p1 != null) cal += p1.val;
            if (p2 != null) cal += p2.val;

            if (pres == null) {
                pres = new ListNode();
                pnow = pres;
            } else {
                ListNode pnew = new ListNode();
                pnow.next = pnew;
                pnow = pnew;
            }
            pnow.val = cal % 10;
            up = cal / 10;
            if (p1 != null)
                p1 = p1.next;
            if (p2 != null)
                p2 = p2.next;
        }
        return pres;
    }
}