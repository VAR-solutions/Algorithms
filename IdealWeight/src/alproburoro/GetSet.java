/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package alproburoro;

/**
 *
 * @author Nadila & Taufiq Idrus
 */
public class GetSet {

    private double tinggi;
    private double kaloriperhari;
    private double lemak;
    private double karbohidrat;
    private double protein;
    private String nama;
    private String gender;
    private double BodyMassIndex;
    private String goals;
    private int usia;
    private String aktivitas;
    private double berat;
    private int urut;

    GetSet(int urut, String nama, String gender, double berat, double tinggi, int usia, double BodyMassIndex, String goal, String aktivitas, double kaloriperhari, double karbohidrat, double lemak, double protein) {
        this.urut = urut;
        this.nama = nama;
        this.gender = gender;
        this.berat = berat;
        this.tinggi = tinggi;
        this.usia = usia;
        this.BodyMassIndex = BodyMassIndex;
        this.goals = goal;
        this.aktivitas = aktivitas;
        this.kaloriperhari = kaloriperhari;
        this.karbohidrat = karbohidrat;
        this.lemak = lemak;
        this.protein = protein;
        

    }
    
    

    public String getNama() {
        return nama;
    }

    public String getGender() {
        return gender;
    }

    public double getWeight() {
        return berat;
    }

    public double getHeight() {
        return tinggi;
    }

    public int getAge() {
        return usia;
    }

    public double getBodyMassIndex() {
        return BodyMassIndex;
    }

    public String getGoals() {
        return goals;
    }

    public String getAktivitas() {
        return aktivitas;
    }

    public double getKaloriperhari1() {
        return kaloriperhari;
    }

    public double getKarbohidrat() {
        return karbohidrat;
    }

    public double getLmeak() {
        return lemak;
    }

    public double getProtein() {
        return protein;
    }
    
    public int urut(){
        return urut;
    }

    public void setNama(String nama) {
        this.nama = nama;
    }

    public void setGender(String gender) {
        this.gender = gender;
    }

    public void setWeight(int berat) {
        this.berat = berat;
    }

    public void setHeight(double tinggi) {
        this.tinggi = tinggi;
    }

    public void setAge(int usia) {
        this.usia = usia;
    }

    public void setBodyMassIndex(double BodyMassIndex) {
        this.BodyMassIndex = BodyMassIndex;
    }

    public void setGoal(String goal) {
        this.goals = goal;
    }

    public void setAktivitas(String aktivitas) {
        this.aktivitas = aktivitas;
    }

    public void setKaloriperhari(double kaloriperhari) {
        this.kaloriperhari = this.kaloriperhari;
    }

    public void setKarbohidrat(double karbohidrat) {
        this.karbohidrat = this.karbohidrat;
    }

    public void setLemak(double lemak) {
        this.lemak = lemak;
    }

    public void setProtein(double protein) {
        this.protein = protein;
    }
}
