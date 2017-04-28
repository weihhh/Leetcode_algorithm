def debug(f,*args,**kwargs):
    from IPython.core.debugger import Pdb
    pdb=Pdb(color_scheme='Linux')
    return pdb.runcall(f,*args,**keargs)