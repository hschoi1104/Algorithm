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
<pre><span class="s0">import </span><span class="s1">sys</span>
<span class="s0">from </span><span class="s1">collections </span><span class="s0">import </span><span class="s1">deque</span>


<span class="s0">def </span><span class="s1">bfs(s):</span>
    <span class="s1">_max = [</span><span class="s2">0</span><span class="s0">, </span><span class="s2">0</span><span class="s1">]</span>
    <span class="s1">chk = [-</span><span class="s2">1</span><span class="s1">] * (V + </span><span class="s2">1</span><span class="s1">)</span>
    <span class="s1">q = deque()</span>
    <span class="s1">q.append(s)</span>
    <span class="s1">chk[s] = </span><span class="s2">0</span>

    <span class="s0">while </span><span class="s1">q:</span>
        <span class="s1">t = q.popleft()</span>
        <span class="s0">for </span><span class="s1">e</span><span class="s0">, </span><span class="s1">w </span><span class="s0">in </span><span class="s1">g[t]:</span>
            <span class="s0">if </span><span class="s1">chk[e] == -</span><span class="s2">1</span><span class="s1">:</span>
                <span class="s1">chk[e] = chk[t] + w</span>
                <span class="s1">q.append(e)</span>
                <span class="s0">if </span><span class="s1">_max[</span><span class="s2">0</span><span class="s1">] &lt; chk[e]:</span>
                    <span class="s1">_max = chk[e]</span><span class="s0">, </span><span class="s1">e</span>
    <span class="s0">return </span><span class="s1">_max</span>


<span class="s1">V = int(sys.stdin.readline())</span>
<span class="s1">g = [[] </span><span class="s0">for </span><span class="s1">_ </span><span class="s0">in </span><span class="s1">range(V + </span><span class="s2">1</span><span class="s1">)]</span>
<span class="s0">for </span><span class="s1">_ </span><span class="s0">in </span><span class="s1">range(V):</span>
    <span class="s1">c = list(map(int</span><span class="s0">, </span><span class="s1">sys.stdin.readline().split()))</span>
    <span class="s0">for </span><span class="s1">e </span><span class="s0">in </span><span class="s1">range(</span><span class="s2">1</span><span class="s0">, </span><span class="s1">len(c) - </span><span class="s2">2</span><span class="s0">, </span><span class="s2">2</span><span class="s1">):</span>
        <span class="s1">g[c[</span><span class="s2">0</span><span class="s1">]].append((c[e]</span><span class="s0">, </span><span class="s1">c[e + </span><span class="s2">1</span><span class="s1">]))</span>

<span class="s1">a</span><span class="s0">, </span><span class="s1">b = bfs(</span><span class="s2">1</span><span class="s1">)</span>
<span class="s1">a</span><span class="s0">, </span><span class="s1">b = bfs(b)</span>
<span class="s1">print(a)</span>
</pre>
</body>
</html>