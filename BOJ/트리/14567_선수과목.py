<html>
<head>
<title>main.py</title>
<meta http-equiv="Content-Type" content="text/html; charset=utf-8">
<style type="text/css">
.s0 { color: #cc7832;}
.s1 { color: #a9b7c6;}
.s2 { color: #6897bb;}
</style>
</head>
<body bgcolor="#2b2b2b">
<table CELLSPACING=0 CELLPADDING=5 COLS=1 WIDTH="100%" BGCOLOR="#606060" >
<tr><td><center>
<font face="Arial, Helvetica" color="#000000">
main.py</font>
</center></td></tr></table>
<pre><span class="s0">import </span><span class="s1">collections</span>


<span class="s0">def </span><span class="s1">solution(cycle):</span>
    <span class="s1">queue = collections.deque()</span>
    <span class="s0">for </span><span class="s1">i </span><span class="s0">in </span><span class="s1">range(</span><span class="s2">1</span><span class="s0">, </span><span class="s1">n + </span><span class="s2">1</span><span class="s1">):</span>
        <span class="s0">if </span><span class="s1">degree[i] == </span><span class="s2">0</span><span class="s1">:</span>
            <span class="s1">queue.append(i)</span>

    <span class="s0">while </span><span class="s1">queue:</span>
        <span class="s1">size = len(queue)</span>
        <span class="s0">while </span><span class="s1">size:</span>
            <span class="s1">cur = queue.popleft()</span>
            <span class="s1">ans[cur] = cycle</span>
            <span class="s0">for </span><span class="s1">i </span><span class="s0">in </span><span class="s1">graph[cur]:</span>
                <span class="s1">degree[i] -= </span><span class="s2">1</span>
                <span class="s0">if </span><span class="s1">degree[i] == </span><span class="s2">0</span><span class="s1">:</span>
                    <span class="s1">queue.append(i)</span>
            <span class="s1">size -= </span><span class="s2">1</span>
        <span class="s1">cycle += </span><span class="s2">1</span>

    <span class="s1">print(*ans[</span><span class="s2">1</span><span class="s1">:])</span>


<span class="s1">n</span><span class="s0">, </span><span class="s1">m = map(int</span><span class="s0">, </span><span class="s1">input().split())</span>
<span class="s1">degree = [</span><span class="s2">0 </span><span class="s0">for </span><span class="s1">_ </span><span class="s0">in </span><span class="s1">range(n + </span><span class="s2">1</span><span class="s1">)]</span>
<span class="s1">ans = [</span><span class="s2">0 </span><span class="s0">for </span><span class="s1">_ </span><span class="s0">in </span><span class="s1">range(n + </span><span class="s2">1</span><span class="s1">)]</span>
<span class="s1">graph = collections.defaultdict(list)</span>

<span class="s0">for </span><span class="s1">_ </span><span class="s0">in </span><span class="s1">range(m):</span>
    <span class="s1">a</span><span class="s0">, </span><span class="s1">b = map(int</span><span class="s0">, </span><span class="s1">input().split())</span>
    <span class="s1">graph[a].append(b)</span>
    <span class="s1">degree[b] += </span><span class="s2">1</span>

<span class="s1">solution(</span><span class="s2">1</span><span class="s1">)</span>
</pre>
</body>
</html>