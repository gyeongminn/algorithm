# [Platinum III] Sojusz - 8557 

[문제 링크](https://www.acmicpc.net/problem/8557) 

### 성능 요약

메모리: 2228 KB, 시간: 0 ms

### 분류

이분 매칭

### 제출 일자

2026년 3월 5일 22:52:33

### 문제 설명

<p>Dawno, dawno temu, w odległej galaktyce istniały dwa państwa, które postanowiły zawrzeć sojusz. Każde z państw obejmowało pewną liczbę planet. Niektóre z planet były połączone wygodnymi <i>tunelami</i> nadprzestrzennymi I generacji. Każdy tunel łączył dwie planety i pozwalał na odbywanie podróży pasażerskich między nimi w krótkim czasie.</p>

<p>Pewnego dnia naukowcy odkryli <i>tunele</i> nadprzestrzenne II generacji, które pozwalały odbywać podróże w jeszcze krótszym czasie. Ulepszenie tunelu starszego typu do tunelu II generacji kosztowało wszędzie tyle samo. Politycy obu państw postanowili umocnić sojusz ulepszając do tuneli II generacji niektóre tunele I generacji łączące planety z różnych państw. Aby żadna planeta nie czuła się skrzywdzona, ustalono, że każda planeta, która już posiadała jakiś tunel I generacji łączący ją z planetą przeciwnego państwa, powinna mieć ulepszony przynajmniej jeden z tych tuneli. Przystąpiono do realizacji planów, ale wydano zbyt dużo pieniędzy, oba państwa zbankrutowały, sojusz się rozpadł, a w galaktyce zapanował kosmiczny chaos.</p>

<p>Obecnie niektórzy historycy badający tamte wydarzenia uważają, że ulepszono wówczas zbyt wiele tuneli, a całego zamieszania można było uniknąć. Z chęcią dowiedzieliby się, jaka była minimalna liczba tuneli, które trzeba było unowocześnić, by spełnić ustalenia polityków. Twoim zadaniem będzie im w tym pomóc.</p>

<p>Napisz program, który:</p>

<ul>
	<li>wczyta ze standardowego wejścia opis sieci tuneli I generacji,</li>
	<li>znajdzie minimalną liczbę tuneli, które należało ulepszyć, aby spełnić wymagania ustalone przez polityków,</li>
	<li>zapisze wynik na standardowe wyjście.</li>
</ul>

### 입력 

 <p>W pierwszym wierszu znajdują się dwie liczby całkowite <em>m</em> i <em>n</em>, oddzielone pojedynczym odstępem i określające odpowiednio liczby planet w pierwszym i drugim państwie, 1 ≤ <em>m</em>, <em>n</em> ≤ 2 000. Przyjmujemy, że planety w pierwszym państwie są ponumerowane liczbami całkowitymi od 1 do <em>m</em>, natomiast w drugim liczbami całkowitymi od <em>m</em> + 1 do <em>n</em> + <em>m</em>. Drugi wiersz zawiera jedną liczbę całkowitą <em>k</em>, 1 ≤ <em>k</em> ≤ 10 000. Jest to liczba tuneli I generacji. Następne <em>k</em> wierszy zawiera opisy tuneli. Pojedynczy wiersz opisuje jeden tunel i zawiera parę liczb <em>a</em>, <em>b</em> oddzielonych pojedynczym odstępem, gdzie <em>a</em> i <em>b</em> są numerami planet połączonych tunelem. Zakładamy, że żaden tunel nie łączy planety z nią samą i że żadna para planet nie jest połączona kilkoma tunelami.</p>

### 출력 

 <p>W pierwszym i jedynym wierszu wyjścia powinna znaleźć się jedna liczba całkowita, będąca minimalną liczbą tuneli, które należało ulepszyć.</p>

