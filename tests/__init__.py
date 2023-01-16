def test_interface():
    from quadtree.libquadtree import Quadtree
    q=Quadtree(10,10,10)
    q.insert(0,.1,.2,.3,.4)
    assert ([0]==(q.query(-1,-1,1,1,1))).all()
    q.remove(0)
    assert len((q.query(-1,-1,1,1,1)))==0
def test_correctedness():
    #TODO
    pass
def test_perf():
    #TODO
    pass