/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package alproburoro;

import java.sql.Connection;
import java.sql.PreparedStatement;

/**
 *
 * @author Nadila
 */
public class data {

    private GetSet[] data2;
    private String[][] temp;
    int nElement = 0;
    private int swappping = 0;

    public data(int Max) {
        data2 = new GetSet[Max];
        //insert(1, "Nadila", "Female", 44, 155, 17, 18, "Maintain Current Weight", "Sedentary", 1395.3, 767.0, 418.0, 209.0);
        //insert(2, "Gintoki", "Male", 65, 177, 28, 20, "Maintain Current Weight", "Active", 2269.75, 1248.0, 680.0, 340.0);
       //insert(3, "Lisa", "Female", 46, 167, 22, 16, "Weight Gain", "Active", 2071.02, 1139.0, 621.0, 310.0);
        //insert(4, "Hijikata", "Male", 68, 177, 28, 21, "Maintain Current Weight", "Active", 2311.75, 1271.0, 693.0, 346.0);
        //insert(5, "Kenma", "Male", 56, 169, 17, 19, "Maintain Current Weight", "Active", 2150.75, 1182.0, 645.0, 322.0);
    }

    public void insert(int urut, String nama, String gender, double berat, double tinggi, int usia, double BodyMassIndex, String goal, String aktivitas, double kaloriperhari, double karbohidrat, double lemak, double protein) {
        data2[nElement] = new GetSet(urut, nama, gender, berat, tinggi, usia, BodyMassIndex, goal, aktivitas, kaloriperhari, karbohidrat, lemak, protein);
        nElement++;
    }
    

    

    public String[][] readData() {
        temp = new String[nElement][12];
        int j = 0;
        for (int i = 0; i < data2.length; i++) {
            if (data2[i] != null) {
                temp[j][0] = data2[i].getNama();
                temp[j][1] = data2[i].getGender();
                temp[j][2] = Double.toString(data2[i].getWeight());
                temp[j][3] = Double.toString(data2[i].getHeight());
                temp[j][4] = Double.toString(data2[i].getAge());
                temp[j][5] = Double.toString(data2[i].getBodyMassIndex());
                temp[j][6] = data2[i].getGoals();
                temp[j][7] = data2[i].getAktivitas();
                temp[j][8] = Double.toString(data2[i].getKaloriperhari1());
                temp[j][9] = Double.toString(data2[i].getKarbohidrat());
                temp[j][10] = Double.toString(data2[i].getLmeak());
                temp[j][11] = Double.toString(data2[i].getProtein());
                j++;
            }
        }
        return temp;
    }

    public void updateAt(int index, GetSet update) {
        data2[index] = update;
    }

    public String getNama(int index) {
        return data2[index].getNama();
    }

    public int size() {
        return nElement;
    }

    public void bubblesort() {
        String hiterasi;
        String hcomparasi;
        String hswap;
        String hwaktu;
        int iterasi = -1;
        int comparasi = 0;
        int swap = 0;
        double totalRuntime = 0;
        GetSet temp;
        for (int i = 0; i < nElement; i++) {
            iterasi++;
            double startTime = System.currentTimeMillis();
            for (int j = i + 1; j < nElement; j++) {
                comparasi++;
                if (data2[i].getBodyMassIndex() < data2[j].getBodyMassIndex()) {
                    temp = data2[i];
                    data2[i] = data2[j];
                    data2[j] = temp;
                    swap++;
                }
            }
            double endTime = System.currentTimeMillis();
            totalRuntime += (endTime - startTime);
        }
        hiterasi = Integer.toString(iterasi);
        hcomparasi = Integer.toString(comparasi);
        hswap = Integer.toString(swap);
        hwaktu = Double.toString(totalRuntime);
        System.out.println("BUBBLE SORT");
        System.out.println("Iterasi : " + hiterasi);
        System.out.println("Comparasi : " + hcomparasi);
        System.out.println("Swap : " + hswap);
        System.out.println("Waktu : " + hwaktu);
        System.out.println("===============================");
    }

    public void insertionsort() {
        String hiterasi;
        String hcomparasi;
        String hswap;
        String hwaktu;
        int iterasi = 0;
        int comparasi = 0;
        int swap = 0;
        double totalRuntime = 0;
        GetSet temp;
        int out, in;
        for (out = 1; out < nElement; out++) {
            double startTime = System.currentTimeMillis();
            temp = data2[out];
            in = out;
            while (in > 0 && data2[in - 1].getBodyMassIndex() < temp.getBodyMassIndex()) {
                data2[in] = data2[in - 1];
                --in;
                comparasi++;
            }
            data2[in] = temp;
            swap++;
            double endTime = System.currentTimeMillis();
            totalRuntime += (endTime - startTime);
        }
        iterasi++;
        hiterasi = Integer.toString(iterasi);
        hcomparasi = Integer.toString(comparasi);
        hswap = Integer.toString(swap);
        hwaktu = Double.toString(totalRuntime);
        System.out.println("INSERTION SORT");
        System.out.println("Iterasi : " + hiterasi);
        System.out.println("Comparasi : " + hcomparasi);
        System.out.println("Swap : " + hswap);
        System.out.println("Waktu : " + hwaktu);
        System.out.println("================================");
    }

    public void insertionsortumur() {
        String hiterasi;
        String hcomparasi;
        String hswap;
        String hwaktu;
        int iterasi = -1;
        int comparasi = 0;
        int swap = 0;
        double totalRuntime = 0;
        GetSet temp;
        int out, in;
        for (out = 1; out < nElement; out++) {
            iterasi++;
            double startTime = System.currentTimeMillis();
            temp = data2[out];
            in = out;
            while (in > 0 && data2[in - 1].getAge() > temp.getAge()) {
                data2[in] = data2[in - 1];
                --in;
                comparasi++;
            }
            data2[in] = temp;
            swap++;
            double endTime = System.currentTimeMillis();
            totalRuntime += (endTime - startTime);
        }
        hiterasi = Integer.toString(iterasi);
        hcomparasi = Integer.toString(comparasi);
        hswap = Integer.toString(swap);
        hwaktu = Double.toString(totalRuntime);
        System.out.println("Iterasi : " + hiterasi);
        System.out.println("Comparasi : " + hcomparasi);
        System.out.println("Swap : " + hswap);
        System.out.println("Waktu : " + hwaktu);
        System.out.println("================================");
    }

    public void insertion() {
        int iterasi = 0;
        int swap = 0;
        int assignment = 0;
        int komparasi = 0;
        int i, curin;
        int swaper = 0;
        for (curin = 0; curin < nElement; curin++) {
            System.out.println("\nIterasi\t " + (++iterasi));
            GetSet temp = data2[curin];
            System.out.println("Temp\t\t= " + temp.getNama());
            i = curin;

            System.out.println("\nKomparasi\t" + (++komparasi) + "\t" + i + " > 0 && data2[" + (i - 1) + "].getNama().compareTo(temp.getNama()) > 0");
            while (i > 0 && data2[i - 1].getNama().compareTo(temp.getNama()) > 0) {
                System.out.println("Assigntment\t" + (++assignment) + "\tdata2[" + i + "] = data2[" + (i - 1) + "]\t\t" + data2[i].getNama()
                        + " = " + data2[i - 1].getNama());
                data2[i] = data2[i - 1];
                i--;
                System.out.println("\nKomparasi\t" + (++komparasi) + "\t" + i + " > 0 && data2[" + (i - 1) + "].getNama().comparseTo(temp.getNama()) > 0");
                swaper++;
            }

            System.out.println("Assigntment\t" + (++assignment) + "\tdata2[" + i + "] = temp\t||\t" + data2[i].getNama() + " = " + temp.getNama());
            data2[i] = temp;

        }

        System.out.println("\nTotal Iterasi\t\t = " + iterasi);
        System.out.println("Total Komparasi\t\t = " + komparasi);
        System.out.println("Total Swap\t\t = " + swaper);
        System.out.println("Total Assignment\t = " + assignment);
    }

    public void SelectionSort() {
        int awal, i, min;
        GetSet temp;
        for (awal = 0; awal < nElement - 1; awal++) {
            min = awal;
            for (i = awal + 1; i < nElement; i++) {
                if (data2[awal].getBodyMassIndex() < data2[i].getBodyMassIndex()) {
                    min = i;
                    temp = data2[awal];
                    data2[awal] = data2[i];
                    data2[i] = temp;
                    
                }
            }
            swappping++;
//            temp = data2[awal];
//            data2[awal] = data2[min];
//            data2[min] = temp;
        }
        System.out.println("\nTotal iterasi: " + Totalliterasi());
        System.out.println("Total perbandingan: " + Totalperbandingan());
        System.out.println("Total swapping: " + Totalswapping());
    }
    
    public void Bubblesort2(){
        int iterasi = 0;
        int komparasi = 0;
        int swap = 0;
        int batas, i;
        for (batas = nElement - 1; batas > 0; batas--) {
            iterasi++;
            for (i = 0; i < batas; i++) {
                komparasi++;
                if(data2[i].getBodyMassIndex() < data2[i + 1].getBodyMassIndex()){
                    swap(i, i+1);
                    swap++;
                }
            }
        }
        System.out.println("Iterasi\t: "+iterasi);
        System.out.println("Komparasi\t: "+komparasi);
        System.out.println("Swap\t: "+swap);
        System.out.println("\n");
    }
    
    public void selectionsort2(){
        int iterasi = 0;
        int komparasi = 0;
        int swap = 0;
        int awal, i, min;
        for (awal = 0; awal < nElement - 1; awal++) {
            min = awal;
            iterasi++;
            for (i = awal+1; i < nElement; i++) {
                komparasi++;
                if(data2[i].getBodyMassIndex()>data2[min].getBodyMassIndex()){
                    min = i;
                }
            }
            swap(awal, min);
            swap++;
        }
        System.out.println("Iterasi\t: "+iterasi);
        System.out.println("Komparasi\t: "+komparasi);
        System.out.println("Swap\t: "+swap);
        System.out.println("\n");
    }

    public void swap(int one, int two) {
        GetSet temp = data2[one];
        data2[one] = data2[two];
        data2[two] = temp;
    }

    public int Totalswapping() {
        return swappping;
    }

    public int Totalliterasi() {
        return (nElement - 1);
    }

    public int Totalperbandingan() {
        return (nElement * (nElement - 1) / 2);
    }

    public void methodbantuan() {
        int min;
        GetSet temp;
        for (int awal = 0; awal < nElement - 1; awal++) {
            min = awal;
            for (int i = awal + 1; i < nElement; i++) {
                if (data2[awal].urut() > data2[i].urut()) {
                    //min = i;
                    temp = data2[awal];
                    data2[awal] = data2[i];
                    data2[i] = temp;
                }
            }

            //swap(awal, min);
        }

    }

    public GetSet peek(int i) {
        return data2[i];
    }
    
   

}
