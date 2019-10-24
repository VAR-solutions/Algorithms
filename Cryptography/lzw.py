def compress(mess):
    n = 256
    dic = {chr(i): i for i in range(n)}
    p = mess[0]
    res = []
    for c in mess[1:]:
        if p+c in dic:
            p = p+c
        else:
            res.append(dic[p])
            dic[p+c] = n
            n += 1
            p = c
    if p:
        res.append(dic[p])
    return res


def decompres(res):
    n = 256
    dic = {i: chr(i) for i in range(n)}
    p = res[0]
    e = ''
    mess = dic[p]
    for c in res[1:]:
        if c not in dic:
            s = dic[p]
            s = s + e
        else:
            s = dic[c]
        mess = mess + s
        e = s[0]
        dic[n] = dic[p] + e
        n += 1
        p = c
    return mess


mess = 'BABAABAAA'
c_mess = compress(mess)
print(c_mess)
d_mess = decompres(c_mess)
print(d_mess)
