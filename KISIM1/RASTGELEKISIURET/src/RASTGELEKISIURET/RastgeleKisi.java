/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package RASTGELEKISIURET;
import java.io.BufferedWriter;
import java.io.File;
import java.io.FileNotFoundException;
import java.io.FileWriter;
import java.io.IOException;
import java.util.Scanner;
/**
 *
 * @author Melike Göncü, Başak Bakar
 */
public class RastgeleKisi {
    Kisi kisi =new Kisi();
    Donusumler donus=new Donusumler();
    
    public void KisiOlustur() throws IOException
    {
        kisi.isimOku();//isim array oluşturulur
        String str =kisi.tcKimlikNoOlustur()+" "+kisi.rastgeleIsimAl()+" "+kisi.yasOlustur()+" "+kisi.telefonNoOlustur()+" "+"("+" "+kisi.imeiNoOlustur()+" "+")"+" "+"\n";
        //kisi sınıfından diğer sınıflara ait fonksiyonlar çağırılır
            try {

        File file = new File("Kisiler.txt");

        // if file doesnt exists, then create it
        if (!file.exists()) {//file yoksa yeni bir file oluştur
            file.createNewFile();
        }

        FileWriter fw = new FileWriter(file.getAbsoluteFile(),true);
        BufferedWriter bw = new BufferedWriter(fw);
        bw.write(str);//str yazılır
        bw.close();

        System.out.println("Done");

    } catch (IOException e) {
        e.printStackTrace();
    }
    }

    
    public void KontrolEt()
    {
        try {
            File f = new File("Kisiler.txt");
            Scanner sc1 = new Scanner(f);
            
            System.out.println("Tc Kontrolü");
            while(sc1.hasNextLine()){//eğer line varsa
            String line = sc1.nextLine();
                String[] details = line.split(" ");//boşluklara göre string array e ata
                if(!kisi.TCNo.TCkontrol(donus.StringToArrayInt(details[0])))//ilk kelime(TC) dönüşümü yapılarak kontrol edilir
                    System.out.println(details[0]+" geçersiz");
                else
                    System.out.println(details[0]+" geçerli");
            }
            
            Scanner sc2 = new Scanner(f);            
            System.out.println("Imei Kontrolü");

            while(sc2.hasNextLine()){//eğer line varsa
                String line = sc2.nextLine();
                String[] details = line.split(" ");//boşluklara göre string array e ata
                if(!kisi.imeiNo.IMEIKontrol(donus.StringToArrayInt(details[6])))//altıncı kelime(İMEİ) dönüşümü yapılarak kontrol edilir
                    System.out.println(details[6]+" geçersiz");
                else
                    System.out.println(details[6]+" geçerli");
            }

        } catch (FileNotFoundException e) {         
            e.printStackTrace();
        }
    }
    public void FileClean()
    {
        File file = new File("Kisiler.txt"); 
          
        if(file.delete()) 
        { 
            System.out.println("File deleted successfully"); 
        } 
        else
        { 
            System.out.println("Failed to delete the file"); 
        } 
    }
    }

