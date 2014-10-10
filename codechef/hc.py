for i in range(input()):
    n = input()
    n_str = str(n)
    set_l = set()
    for k in n_str:
        set_l.add(k)
        #print set_l
    m = 1
    while len(set_l) < 10 :
        m+=1
        j = m*n
        n_str = str(j)
        for k in n_str:
            set_l.add(k)
        #print set_l
    print m