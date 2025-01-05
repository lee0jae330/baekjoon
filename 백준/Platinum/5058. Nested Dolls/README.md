# [Platinum V] Nested Dolls - 5058 

[문제 링크](https://www.acmicpc.net/problem/5058) 

### 성능 요약

메모리: 2560 KB, 시간: 516 ms

### 분류

이분 탐색, 가장 긴 증가하는 부분 수열: O(n log n)

### 제출 일자

2025년 1월 5일 17:35:50

### 문제 설명

<p>Dilworth is the world’s most prominent collector of Russian nested dolls: he literally has thousands of them! You know, the wooden hollow dolls of different sizes of which the smallest doll is contained in the second smallest, and this doll is in turn contained in the next one and so forth. One day he wonders if there is another way of nesting them so he will end up with fewer nested dolls? After all, that would make his collection even more magnificent! He unpacks each nested doll and measures the width and height of each contained doll. A doll with width w<sub>1</sub> and height h<sub>1</sub> will fit in another doll of width w<sub>2</sub> and height h<sub>2</sub> if and only if w<sub>1</sub> < w<sub>2</sub> and h<sub>1</sub> < h<sub>2</sub>. Can you help him calculate the smallest number of nested dolls possible to assemble from his massive list of measurements?</p>

### 입력 

 <p>On the first line of input is a single positive integer 1 ≤ t ≤ 20 specifying the number of test cases to follow. Each test case begins with a positive integer 1 ≤ m ≤ 20000 on a line of itself telling the number of dolls in the test case. Next follow 2m positive integers w<sub>1</sub>, h<sub>1</sub>, w<sub>2</sub>, h<sub>2</sub>, . . . , w<sub>m</sub>, h<sub>m</sub>, where w<sub>i</sub> is the width and hi is the height of doll number i. 1 ≤ w<sub>i</sub>, h<sub>i</sub> ≤ 10000 for all i.</p>

### 출력 

 <p>For each test case there should be one line of output containing the minimum number of nested dolls possible.</p>

