/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package RASTGELEKISIURET;

/**
 *
 * @author Melike Göncü, Başak Bakar
 */
public class IMEINo {
    private final int IMEIDigit=15;//sabit imei digit sayısı
    private int IMEINo[]=new int [IMEIDigit];
    private int IMEICiftDigit=0;
    private int IMEITekDigit=0;      
    Rastgele random= new Rastgele();//rastgele methodunun çağırılması

    protected int[] IMEINoOlustur()
    {         
        for(int i=0;i<IMEIDigit-1;i++)
        {
        IMEINo[i]=random.uretimRastgeleRakam(10);//ilk 14 rakam rastgele üretilir 
        }
        for(int i=0;i<IMEIDigit-2;i++)
        {
            IMEICiftDigit+=IMEINo[i];
            i++;
        }
        
        for(int i=1;i<IMEIDigit-1;i++)
        {
            IMEITekDigit+=((2*IMEINo[i]/10)+(2*IMEINo[i]%10));
            i++;
        }
        
        IMEINo[14]=((((IMEICiftDigit+IMEITekDigit)/10+1)*10-(IMEICiftDigit+IMEITekDigit))%10);//15.eleman formülü
        
         
        return IMEINo;//imei array döner
    }
    
    protected boolean IMEIKontrol(int arr[])
    {
        if(arr.length!=IMEIDigit) return false;//parametre array in uzunluğunun kontrolü
        for(int i=0;i<arr.length-2;i++)
        {
            IMEICiftDigit+=arr[i];
            i++;
        }
        for(int i=1;i<arr.length-1;i++)
        {
            IMEITekDigit+=((2*arr[i]/10)+(2*arr[i]%10));
            i++;
        }
        return arr[14] == ((((IMEICiftDigit+IMEITekDigit)/10+1)*10-(IMEICiftDigit+IMEITekDigit))%10);//parametre array in 15. eleman kontrolü
    }
}
