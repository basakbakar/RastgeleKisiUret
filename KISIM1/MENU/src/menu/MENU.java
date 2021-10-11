/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package menu;


import RASTGELEKISIURET.RastgeleKisi;
import java.io.IOException;
import java.util.Scanner;
/**
 *
 * @author Melike Göncü, Başak Bakar
 */
public class MENU {

    public static void main(String[] args) throws IOException {
        System.out.println("1-Rastgele Kişi Üret");
        System.out.println("2-Üretilmiş Dosya Kontrol Et");
        System.out.println("3-Çıkış");
        
        Scanner input =new Scanner(System.in);
        int secenek= input.nextInt();//ilk seçenek alınır
        RastgeleKisi kisi1= new RastgeleKisi();//rastgeleKisi nesnesi oluşturulur
         
        while(secenek!=3){
            
        switch(secenek){
            
            case 1:
                kisi1.KisiOlustur();
                break;
                
            case 2:
                kisi1.KontrolEt();
                break;
                
            case 3:
                kisi1.FileClean();
                System.out.println("CIKIS YAPILDI");
                break;
                
            default:
                throw new IllegalArgumentException("Gecersiz rakam");
            }
        secenek= input.nextInt();//seçenek 1-2 ise alınmaya devam edilir
        }
        
    }
}
    

