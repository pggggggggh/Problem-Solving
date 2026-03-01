class Solution {
    fun reorganizeString(s: String): String {
        val cnt = IntArray(26)
        for (i in 0..<s.length) cnt[s[i].code - 'a'.code]++
        val sortedS = s.toCharArray().sortedWith { x,y -> 
            if (cnt[x.code-'a'.code] == cnt[y.code-'a'.code]) x.code-y.code
            else cnt[y.code-'a'.code] - cnt[x.code-'a'.code]
        }
        
        val res = CharArray(s.length)
        var ptr = 0
        for (i in 0..<s.length step(2)) res[i] = sortedS[ptr++]
        for (i in 1..<s.length step(2)) res[i] = sortedS[ptr++]
        for (i in 1..<s.length) {
            if (res[i] == res[i-1]) return ""
        }

        return res.concatToString()
    }
}