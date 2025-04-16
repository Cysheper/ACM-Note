class node:
    def __init__(self, a, b):
        self.a = a  # 节点值
        self.b = b  # 节点权重

lis = []
for i in range(10):
    lis.append(node(i, i + 1))  # 创建10个节点，值为0-9，权重为1-10

lis.sort(key=lambda x: x.b)  # 按照权重升序排列