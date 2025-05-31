lis = [5, 5, 10, 10, 15, 15, 20, 20, 25, 25]
st = set()
def dfs(pos, num):
    if pos == 10: 
        st.add(num)
        return;
    dfs(pos + 1, num + lis[pos])
    dfs(pos + 1, num)
    
dfs(0, 0);
print(len(st))

    
