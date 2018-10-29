package alproburoro;

import java.sql.Connection;
import java.sql.DriverManager;
import java.sql.ResultSet;
import java.sql.Statement;
 
public class connection {
    public Connection variabel; //Untuk membuat joneksi dari java ke database mysql
    public Statement cek; //untuk menampung sebuah query yang digunakan untuk mengolah data dalam database
    public ResultSet set; //menampung hasil eksekusi dari sebuah statement
    
    public Connection getkoneksi(){
        try {
            Class.forName("com.mysql.jdbc.Driver");
            variabel = DriverManager.getConnection("jdbc:mysql://localhost/dila","root",""); //untuk menghubungkan dengan localhost yang diberi nama "dila"
            System.out.println("koneksi sukses");
            
        } catch (Exception e){
            System.out.println("koneksi gagal"+ e);
        }
        return variabel; //karena method bertipe connection jadi harus mengembalikan sebuah value yang sama dengan definisi method
    }
    
}