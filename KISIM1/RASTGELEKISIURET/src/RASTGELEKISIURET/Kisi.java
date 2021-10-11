/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package RASTGELEKISIURET;

import java.io.BufferedReader;
import java.io.FileReader;
import java.util.ArrayList;
import java.io.IOException;


/**
 *
 * @author Melike Göncü, Başak Bakar
 */

public class Kisi {
    KimlikNo TCNo=new KimlikNo();//kisi sınıfında nesneler oluşturulur
    IMEINo imeiNo=new IMEINo();
    Telefon telefon=new Telefon();
    Rastgele random=new Rastgele();    
    Donusumler donus=new Donusumler();

    private String fileName="random_isimler.txt";
    ArrayList<String> isimler = new ArrayList<>();//isim tutmak için arraylist
    public void isimOku() throws IOException
    {
        BufferedReader reader;
		try {
			reader = new BufferedReader(new FileReader(fileName));
			String line = reader.readLine();//dosya line by line okunur
			while (line != null) {//line bitene kadar
				//System.out.println(line);
				// read next line
                                isimler.add(line);//arraylist e isim ekle
				line = reader.readLine();
			}
			reader.close();
		} catch (IOException e)
                {e.printStackTrace();
		}
    }
    public String rastgeleIsimAl()
    {
        return isimler.get(random.uretimRastgeleRakam(isimler.size()));//isimler boyutu gönderilerek random isim seçilir
    }
    public String tcKimlikNoOlustur()
    {     
        return donus.IntToString(TCNo.TCkontrollugenerate(),TCNo.TCkontrollugenerate().length);//array->string dönüşümü yapılır 

    }
    
    public String yasOlustur()
    {
        return Integer.toString(random.uretimRastgeleRakam(100));//0-99 arası yaş üretimi
    }
    
    public String telefonNoOlustur()
    {               
        return donus.IntToString(telefon.telNoOlustur(),telefon.telNoOlustur().length);//array->string dönüşümü yapılır

    }        
    
    public String imeiNoOlustur()
    {
        return donus.IntToString(imeiNo.IMEINoOlustur(),imeiNo.IMEINoOlustur().length);//array->string dönüşümü yapılır
    }
}
