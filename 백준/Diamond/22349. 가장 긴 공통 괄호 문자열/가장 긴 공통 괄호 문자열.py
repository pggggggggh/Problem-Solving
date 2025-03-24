import sys
from bisect import bisect_left

input = sys.stdin.readline


# ---------------------------------------
# 구간 최소 쿼리를 위한 세그먼트 트리 구현
# ---------------------------------------
class MinSeg:
    def __init__(self, n):
        self.size = 1
        while self.size < n:
            self.size <<= 1
        # 세그먼트 트리를 매우 큰 값으로 초기화
        self.seg = [10**15] * (2 * self.size)

    def update(self, idx, val):
        # 리프(leaf) 노드 위치
        idx += self.size
        self.seg[idx] = val
        idx //= 2
        # 조상 노드 갱신
        while idx:
            self.seg[idx] = min(self.seg[idx << 1], self.seg[(idx << 1) + 1])
            idx //= 2

    def query(self, left, right):
        # [left, right] 구간 최솟값
        res = 10**15
        left += self.size
        right += self.size
        while left <= right:
            if left & 1:
                res = min(res, self.seg[left])
                left += 1
            if not (right & 1):
                res = min(res, self.seg[right])
                right -= 1
            left >>= 1
            right >>= 1
        return res


# ---------------------------------------
# 모듈로 리스트
# ---------------------------------------
MOD = [
    100000000019,
    100000000057,
    100000000063,
    100000000069,
    100000000099,
    100000000103,
    100000000129,
    100000000163,
    100000000169,
    100000000193,
    100000000223,
    100000000237,
    100000000253,
    100000000267,
    100000000279,
    100000000319,
    100000000323,
    100000000379,
    96233133937119371,
    15771418243918223,
    82734782537986603,
    38683170735499313,
    68298383632600031,
    103958425906205207,
    78196220870063137,
    64303510333845161,
    88920073713275417,
    31421175340817777,
    1000000000000000061,
    1000000000000000381,
]

SZ = len(MOD)  # 30


# ---------------------------------------
# 거듭제곱 모듈로 (파이썬 내장 pow로 대체 가능)
# ---------------------------------------
def modexp(base, exp, m):
    # Python 내장 pow(base, exp, m) 사용 가능
    return pow(base, exp, m)


# ---------------------------------------
# 문제 해결 함수
# ---------------------------------------
def solve():
    s, t = input().split()
    n, m = len(s), len(t)

    # C++ 코드와 유사하게 문자열 앞에 '$'를 붙여서 인덱스 1부터 사용
    s = "$" + s
    t = "$" + t

    # 각 문자열의 '(' -> +1, ')' -> -1에 대한 접두사합 관리용 세그먼트 트리
    psum = MinSeg(n + 1)
    psumb = MinSeg(m + 1)

    # s에 대한 세그먼트 트리 구축
    cur_val = 0
    psum.update(0, 0)
    for i in range(1, n + 1):
        if s[i] == "(":
            cur_val += 1
        else:
            cur_val -= 1
        psum.update(i, cur_val)

    # t에 대한 세그먼트 트리 구축
    cur_val = 0
    psumb.update(0, 0)
    for i in range(1, m + 1):
        if t[i] == "(":
            cur_val += 1
        else:
            cur_val -= 1
        psumb.update(i, cur_val)

    # 가능한 최대 길이를 2 * mid 형태로 탐색 (mid는 올바른 괄호 쌍 개수)
    lo, hi = 0, min(n, m) // 2 + 1

    while lo + 1 < hi:
        mid = (lo + hi) // 2
        length = mid * 2

        # s에서 길이가 length인 올바른 괄호 부분 문자열들의 해시를 모두 구해 보관
        hash_set = []
        # 해시 계산용 cur
        cur_hash = [0] * SZ

        # 초기 구간 [1..length]
        for i in range(1, length + 1):
            if s[i] == "(":
                for k in range(SZ):
                    # 3^(length - i) mod MOD[k] 를 더한다
                    cur_hash[k] = (cur_hash[k] + modexp(3, length - i, MOD[k])) % MOD[k]

        # 올바른 괄호 부분 문자열인지(접두사합 변화량 = 0, 구간 최솟값 >= 시작점의 접두사합) 체크
        if psum.query(length, length) == psum.query(0, 0) and psum.query(
            0, length
        ) >= psum.query(0, 0):
            hash_set.append(tuple(cur_hash))

        # 슬라이딩 윈도우로 s의 다른 길이 length 부분 문자열 처리
        for i in range(length + 1, n + 1):
            # 구간이 한 칸 이동하므로, s[i-length]의 '(' 기여도 제거
            if s[i - length] == "(":
                for k in range(SZ):
                    # 가장 높은 자릿수(3^(length-1))를 뺀다
                    # 음수가 되지 않도록 MOD 더해주기
                    cur_hash[k] = (
                        cur_hash[k] - modexp(3, length - 1, MOD[k]) + MOD[k]
                    ) % MOD[k]

            # 전체를 한 자리(×3) 왼쪽 시프트한 것처럼 처리
            for k in range(SZ):
                cur_hash[k] = (cur_hash[k] * 3) % MOD[k]

            # 새로 들어오는 s[i]가 '('이면 +1
            if s[i] == "(":
                for k in range(SZ):
                    cur_hash[k] = (cur_hash[k] + 1) % MOD[k]

            # 올바른 괄호 부분 문자열인지 체크
            # psum.query(i,i) == psum.query(i-length, i-length) -> 접두사합 차이 = 0
            # psum.query(i-length, i) >= psum.query(i-length, i-length) -> 구간 내 최소값이 시작점 이상
            if psum.query(i, i) == psum.query(i - length, i - length) and psum.query(
                i - length, i
            ) >= psum.query(i - length, i - length):
                hash_set.append(tuple(cur_hash))

        # s에서의 해시값 집합을 정렬 후 중복 제거
        hash_set.sort()
        # 파이썬에서는 직접 unique 처리
        unique_hashes = []
        prev = None
        for h in hash_set:
            if h != prev:
                unique_hashes.append(h)
                prev = h
        hash_set = unique_hashes

        # t에서 동일한 해시를 찾을 수 있는지 확인
        cur_hash_t = [0] * SZ
        # 초기 구간 [1..length]에 대한 해시
        for i in range(1, length + 1):
            if t[i] == "(":
                for k in range(SZ):
                    cur_hash_t[k] = (
                        cur_hash_t[k] + modexp(3, length - i, MOD[k])
                    ) % MOD[k]

        good = False
        # 이분 탐색 같은 느낌으로 lower_bound 대신 파이썬 bisect 사용
        # 첫 번째 구간 체크
        if psumb.query(length, length) == psumb.query(0, 0) and psumb.query(
            0, length
        ) >= psumb.query(0, 0):
            # bisect_left
            import math

            pos = bisect_left(hash_set, tuple(cur_hash_t))
            if pos < len(hash_set) and hash_set[pos] == tuple(cur_hash_t):
                good = True

        # 슬라이딩 윈도우로 t의 나머지 구간 확인
        if not good:
            for i in range(length + 1, m + 1):
                if t[i - length] == "(":
                    for k in range(SZ):
                        cur_hash_t[k] = (
                            cur_hash_t[k] - modexp(3, length - 1, MOD[k]) + MOD[k]
                        ) % MOD[k]

                for k in range(SZ):
                    cur_hash_t[k] = (cur_hash_t[k] * 3) % MOD[k]

                if t[i] == "(":
                    for k in range(SZ):
                        cur_hash_t[k] = (cur_hash_t[k] + 1) % MOD[k]

                # 유효 괄호 부분 문자열인지 체크
                if psumb.query(i, i) == psumb.query(
                    i - length, i - length
                ) and psumb.query(i - length, i) >= psumb.query(i - length, i - length):

                    pos = bisect_left(hash_set, tuple(cur_hash_t))
                    if pos < len(hash_set) and hash_set[pos] == tuple(cur_hash_t):
                        good = True
                        break

        if good:
            lo = mid
        else:
            hi = mid

    print(lo * 2)


def main():
    t = int(input())
    for _ in range(t):
        solve()


if __name__ == "__main__":
    main()
