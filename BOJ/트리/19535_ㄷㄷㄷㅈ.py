<html>
<head>
<title>main.py</title>
<meta http-equiv="Content-Type" content="text/html; charset=utf-8">
<style type="text/css">
.s0 { color: #cc7832;}
.s1 { color: #a9b7c6;}
.s2 { color: #6897bb;}
.s3 { color: #6a8759;}
</style>
</head>
<body bgcolor="#2b2b2b">
<table CELLSPACING=0 CELLPADDING=5 COLS=1 WIDTH="100%" BGCOLOR="#606060" >
<tr><td><center>
<font face="Arial, Helvetica" color="#000000">
main.py</font>
</center></td></tr></table>
<pre><span class="s0">import </span><span class="s1">sys</span>
<span class="s0">from </span><span class="s1">math </span><span class="s0">import </span><span class="s1">comb</span>

<span class="s1">read = sys.stdin.readline</span>


<span class="s0">def </span><span class="s1">solution():</span>
    <span class="s0">for </span><span class="s1">_ </span><span class="s0">in </span><span class="s1">range(n-</span><span class="s2">1</span><span class="s1">):</span>
        <span class="s1">s</span><span class="s0">, </span><span class="s1">e = map(int</span><span class="s0">, </span><span class="s1">read().split())</span>
        <span class="s1">edge.append([s</span><span class="s0">, </span><span class="s1">e])</span>
        <span class="s1">degree[s] += </span><span class="s2">1</span>
        <span class="s1">degree[e] += </span><span class="s2">1</span>
    <span class="s1">d = </span><span class="s2">0</span>
    <span class="s1">g = </span><span class="s2">0</span>
    <span class="s0">for </span><span class="s1">e </span><span class="s0">in </span><span class="s1">edge:</span>
        <span class="s1">d += (degree[e[</span><span class="s2">0</span><span class="s1">]] - </span><span class="s2">1</span><span class="s1">) * (degree[e[</span><span class="s2">1</span><span class="s1">]] - </span><span class="s2">1</span><span class="s1">)</span>

    <span class="s0">for </span><span class="s1">i </span><span class="s0">in </span><span class="s1">range(n + </span><span class="s2">1</span><span class="s1">):</span>
        <span class="s0">if </span><span class="s1">degree[i] &gt;= </span><span class="s2">3</span><span class="s1">:</span>
            <span class="s1">g += comb(degree[i]</span><span class="s0">, </span><span class="s2">3</span><span class="s1">)</span>

    <span class="s0">if </span><span class="s1">d == g * </span><span class="s2">3</span><span class="s1">:</span>
        <span class="s1">ans = </span><span class="s3">&quot;DUDUDUNGA&quot;</span>
    <span class="s0">else</span><span class="s1">:</span>
        <span class="s1">ans = </span><span class="s3">&quot;D&quot; </span><span class="s0">if </span><span class="s1">d &gt; g * </span><span class="s2">3 </span><span class="s0">else </span><span class="s3">&quot;G&quot;</span>

    <span class="s1">print(ans)</span>


<span class="s1">n = int(read())</span>

<span class="s1">edge = []</span>
<span class="s1">degree = [</span><span class="s2">0 </span><span class="s0">for </span><span class="s1">_ </span><span class="s0">in </span><span class="s1">range(n + </span><span class="s2">1</span><span class="s1">)]</span>
<span class="s1">solution();</span>
</pre>
</body>
</html>