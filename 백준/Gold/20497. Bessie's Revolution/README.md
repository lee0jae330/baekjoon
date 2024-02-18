# [Gold IV] Bessie's Revolution - 20497 

[문제 링크](https://www.acmicpc.net/problem/20497) 

### 성능 요약

메모리: 2024 KB, 시간: 0 ms

### 분류

너비 우선 탐색, 브루트포스 알고리즘, 깊이 우선 탐색, 그래프 이론, 그래프 탐색

### 제출 일자

2024년 2월 19일 04:40:50

### 문제 설명

<p>Bessie는 John's Farm의 우민(牛民)이자 혁명 전사이다. 본래 John's Farm의 터는 Bessie와 소들이 평화롭게 풀을 뜯던 초원이었으나, John이 자본을 앞세워 불도저를 밀고 들어와 Farm을 차리면서 모든 것이 달라졌다.</p>

<blockquote>
<p style="text-align: center;"><em>그리하여 이 언덕들</em></p>

<p style="text-align: center;"><em>따사로운 하늘</em></p>

<p style="text-align: center;"><em>이 나무들의 윤곽이</em></p>

<p style="text-align: center;"><em>지금까지 우리가 부여해왔던 허망한 의미를 단숨에 잃어버리고서</em></p>

<p style="text-align: center;"><em>이제부터는 잃어버린 낙원보다도 더 먼 존재로 변해버리는 것이다.</em></p>
</blockquote>

<p>Bessie는 Amy와 John이 있는 주방을 습격하고, 농장을 탈환하려고 한다.</p>

<p>Bessie와 참모진들은 주방의 지도를 입수했다. Bessie는 주방에 기습 병력을 배치하여 Amy와 John을 포위할 계획이다. Bessie는 John's Farm의 최고 전사인 당신을 투입하기로 했다. 당신의 임무는 주방의 한 격자에 장애물로 위장해 잠복하는 것이다. 당신이 잠복함으로 인해, 잠복한 격자가 속한 공간이 두 개 이상의 공간으로 분리되고, 그 공간들 사이의 이동이 불가능해져야 한다. 다시 말해, 잠복한 칸을 거치면 서로 이동할 수 있지만, 잠복한 칸을 거치지 않으면 서로 이동할 수 없는 두 격자가 존재해야 한다. 격자 간의 이동은 상하좌우 이동 <mjx-container class="MathJax" jax="CHTML" style="font-size: 109%; position: relative;"><mjx-math class="MJX-TEX" aria-hidden="true"><mjx-mo class="mjx-n"><mjx-c class="mjx-c28"></mjx-c></mjx-mo><mjx-mi class="mjx-i"><mjx-c class="mjx-c1D45F TEX-I"></mjx-c></mjx-mi><mjx-mo class="mjx-n" space="3"><mjx-c class="mjx-c2B"></mjx-c></mjx-mo><mjx-mn class="mjx-n" space="3"><mjx-c class="mjx-c31"></mjx-c></mjx-mn><mjx-mo class="mjx-n"><mjx-c class="mjx-c2C"></mjx-c></mjx-mo><mjx-mi class="mjx-i" space="2"><mjx-c class="mjx-c1D450 TEX-I"></mjx-c></mjx-mi><mjx-mo class="mjx-n"><mjx-c class="mjx-c29"></mjx-c></mjx-mo><mjx-mo class="mjx-n"><mjx-c class="mjx-c2C"></mjx-c></mjx-mo><mjx-mo class="mjx-n" space="2"><mjx-c class="mjx-c28"></mjx-c></mjx-mo><mjx-mi class="mjx-i"><mjx-c class="mjx-c1D45F TEX-I"></mjx-c></mjx-mi><mjx-mo class="mjx-n" space="3"><mjx-c class="mjx-c2212"></mjx-c></mjx-mo><mjx-mn class="mjx-n" space="3"><mjx-c class="mjx-c31"></mjx-c></mjx-mn><mjx-mo class="mjx-n"><mjx-c class="mjx-c2C"></mjx-c></mjx-mo><mjx-mi class="mjx-i" space="2"><mjx-c class="mjx-c1D450 TEX-I"></mjx-c></mjx-mi><mjx-mo class="mjx-n"><mjx-c class="mjx-c29"></mjx-c></mjx-mo><mjx-mo class="mjx-n"><mjx-c class="mjx-c2C"></mjx-c></mjx-mo><mjx-mo class="mjx-n" space="2"><mjx-c class="mjx-c28"></mjx-c></mjx-mo><mjx-mi class="mjx-i"><mjx-c class="mjx-c1D45F TEX-I"></mjx-c></mjx-mi><mjx-mo class="mjx-n"><mjx-c class="mjx-c2C"></mjx-c></mjx-mo><mjx-mi class="mjx-i" space="2"><mjx-c class="mjx-c1D450 TEX-I"></mjx-c></mjx-mi><mjx-mo class="mjx-n" space="3"><mjx-c class="mjx-c2B"></mjx-c></mjx-mo><mjx-mn class="mjx-n" space="3"><mjx-c class="mjx-c31"></mjx-c></mjx-mn><mjx-mo class="mjx-n"><mjx-c class="mjx-c29"></mjx-c></mjx-mo><mjx-mo class="mjx-n"><mjx-c class="mjx-c2C"></mjx-c></mjx-mo><mjx-mo class="mjx-n" space="2"><mjx-c class="mjx-c28"></mjx-c></mjx-mo><mjx-mi class="mjx-i"><mjx-c class="mjx-c1D45F TEX-I"></mjx-c></mjx-mi><mjx-mo class="mjx-n"><mjx-c class="mjx-c2C"></mjx-c></mjx-mo><mjx-mi class="mjx-i" space="2"><mjx-c class="mjx-c1D450 TEX-I"></mjx-c></mjx-mi><mjx-mo class="mjx-n" space="3"><mjx-c class="mjx-c2212"></mjx-c></mjx-mo><mjx-mn class="mjx-n" space="3"><mjx-c class="mjx-c31"></mjx-c></mjx-mn><mjx-mo class="mjx-n"><mjx-c class="mjx-c29"></mjx-c></mjx-mo></mjx-math><mjx-assistive-mml unselectable="on" display="inline"><math xmlns="http://www.w3.org/1998/Math/MathML"><mo stretchy="false">(</mo><mi>r</mi><mo>+</mo><mn>1</mn><mo>,</mo><mi>c</mi><mo stretchy="false">)</mo><mo>,</mo><mo stretchy="false">(</mo><mi>r</mi><mo>−</mo><mn>1</mn><mo>,</mo><mi>c</mi><mo stretchy="false">)</mo><mo>,</mo><mo stretchy="false">(</mo><mi>r</mi><mo>,</mo><mi>c</mi><mo>+</mo><mn>1</mn><mo stretchy="false">)</mo><mo>,</mo><mo stretchy="false">(</mo><mi>r</mi><mo>,</mo><mi>c</mi><mo>−</mo><mn>1</mn><mo stretchy="false">)</mo></math></mjx-assistive-mml><span aria-hidden="true" class="no-mathjax mjx-copytext">$(r+1,c), (r-1,c), (r,c+1), (r,c-1)$</span></mjx-container>이다. 물론, 격자 밖으로의 이동은 불가능하며 씽크대 또는 장애물이 존재하는 격자에는 잠복할 수 없다.</p>

### 입력 

 <p>첫 번째 줄에 격자의 크기 <mjx-container class="MathJax" jax="CHTML" style="font-size: 109%; position: relative;"><mjx-math class="MJX-TEX" aria-hidden="true"><mjx-mi class="mjx-i"><mjx-c class="mjx-c1D441 TEX-I"></mjx-c></mjx-mi></mjx-math><mjx-assistive-mml unselectable="on" display="inline"><math xmlns="http://www.w3.org/1998/Math/MathML"><mi>N</mi></math></mjx-assistive-mml><span aria-hidden="true" class="no-mathjax mjx-copytext">$N$</span></mjx-container>이 주어진다.</p>

<p>두 번째 줄부터 <mjx-container class="MathJax" jax="CHTML" style="font-size: 109%; position: relative;"><mjx-math class="MJX-TEX" aria-hidden="true"><mjx-mi class="mjx-i"><mjx-c class="mjx-c1D441 TEX-I"></mjx-c></mjx-mi></mjx-math><mjx-assistive-mml unselectable="on" display="inline"><math xmlns="http://www.w3.org/1998/Math/MathML"><mi>N</mi></math></mjx-assistive-mml><span aria-hidden="true" class="no-mathjax mjx-copytext">$N$</span></mjx-container>개의 줄에 걸쳐 <mjx-container class="MathJax" jax="CHTML" style="font-size: 109%; position: relative;"><mjx-math class="MJX-TEX" aria-hidden="true"><mjx-mi class="mjx-i"><mjx-c class="mjx-c1D441 TEX-I"></mjx-c></mjx-mi><mjx-mo class="mjx-n" space="3"><mjx-c class="mjx-cD7"></mjx-c></mjx-mo><mjx-mi class="mjx-i" space="3"><mjx-c class="mjx-c1D441 TEX-I"></mjx-c></mjx-mi></mjx-math><mjx-assistive-mml unselectable="on" display="inline"><math xmlns="http://www.w3.org/1998/Math/MathML"><mi>N</mi><mo>×</mo><mi>N</mi></math></mjx-assistive-mml><span aria-hidden="true" class="no-mathjax mjx-copytext">$N \times N$</span></mjx-container> 크기의 주방의 평면도가 주어진다.</p>

### 출력 

 <p>문제에서 제시한 조건에 맞게 잠복할 수 있는 격자의 개수를 출력한다.</p>

