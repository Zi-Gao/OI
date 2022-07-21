from cyaron import *
for i in range(1, 11):
    test_data = IO(file_prefix="", data_id=i)
    n=i*10000*2
    m=i*20000*2
    graph = Graph.graph(n,m,directed=True,repeated_edges=False,self_loop=False,weight_limit=(-50,1000))
    print("data",i,"finishes making now")
    print("data",i,"finishes making now")
    print("data",i,"starts outing now")
    s = randint(1, n)
    test_data.input_writeln(n,m,s)
    test_data.input_writeln(graph.to_str(shuffle=True))
    print("data",i,"finishes outputting now")
    print("data",i,"starts runing now")
    test_data.output_gen("C:\\Users\\Administrator\\Desktop\\OI\\Documents\\Projects\\GraphTheory\\GraphTheoryTest\\source\\std\\spfa.exe")
    print("data",i,"finishes running now")
