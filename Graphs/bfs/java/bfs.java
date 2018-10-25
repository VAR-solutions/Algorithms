import java.util.*;

public class bfs {

    private Queue<Nodo> cola;
    static ArrayList<Nodo> nodes=new ArrayList<Nodo>();
    static class Nodo
    {
        int datos;
        boolean visitado;
        List<Nodo> vecinos;

        Nodo(int datos)
        {
            this.datos=datos;
            this.vecinos=new ArrayList<>();

        }
        public void addVecinos(Nodo nVecino)
        {
            this.vecinos.add(nVecino);
        }
        public List<Nodo> getVecninos() {
            return vecinos;
        }
        public void setVecinos(List<Nodo> vecinos) {
            this.vecinos = vecinos;
        }
    }

    public bfs()
    {
        cola = new LinkedList<Nodo>();
    }

    public void bfs(Nodo nodo)
    {
        cola.add(nodo);
        nodo.visitado=true;
        while (!cola.isEmpty())
        {

            Nodo e=cola.remove();
            System.out.print(e.datos + "t");
            List<Nodo> vecinos=e.getVecninos();
            for (int i = 0; i < vecinos.size(); i++) {
                Nodo n=vecinos.get(i);
                if(n!=null && !n.visitado)
                {
                    cola.add(n);
                    n.visitado=true;
                }
            }

        }
    }

    public static void main(String arg[])
    {

        Nodo n1 =new Nodo(4);
        Nodo n2 =new Nodo(1);
        Nodo n3 =new Nodo(2);
        Nodo n4 =new Nodo(3);

        n1.addVecinos(n2);
        n1.addVecinos(n3);
        n2.addVecinos(n4);
        n3.addVecinos(n2);
        n4.addVecinos(n1);
        bfs bfsTest = new bfs();
        bfsTest.bfs(n1);
    }
}
