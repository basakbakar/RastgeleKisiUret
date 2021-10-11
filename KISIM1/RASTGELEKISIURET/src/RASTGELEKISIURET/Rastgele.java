/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package RASTGELEKISIURET;
import java.lang.System;
/**
 *
 * @author Melike Göncü, Başak Bakar
 */
public class Rastgele {
    protected int uretimRastgeleRakam(int a){//modunun alınması istenene sayı girilir
        long instantTime =(System.nanoTime())/100;//programın çalışmasının hızlı olması sebebiyle nanosaniye long türünden tutulur
        int rastgeleRakam=(int)(instantTime%a);//alınan nanosaniye modunun alınması istenen sayıya bölünerek rastgele sayı elde edilir
        return rastgeleRakam;
    }
}
