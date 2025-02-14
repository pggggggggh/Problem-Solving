-- 코드를 입력하세요
SELECT PT_NAME
      ,PT_NO
      ,GEND_CD
      ,AGE
      ,COALESCE(TLNO, 'NONE') AS TLNO -- 다른 풀이도 가능
FROM PATIENT
WHERE AGE <= 12
AND GEND_CD = 'W'
ORDER BY AGE DESC
        ,PT_NAME