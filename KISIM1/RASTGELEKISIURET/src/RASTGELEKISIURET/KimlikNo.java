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
public class KimlikNo {
    private final int TCdigit=11;//sabit digit hanesi sayısı
    private int TCno[]=new int [TCdigit];

    protected boolean TCkontrol(int arr[])//oluşturulma kurallarına göre kontrol edilir
    {
        if(arr[0]==0)
            return false;
        else if(arr.length!=TCdigit)
            return false;
        else if(((arr[0]+arr[1]+arr[2]+arr[3]+arr[4]+arr[5]+arr[6]+arr[7]+arr[8]+arr[9])%10)!=arr[10])
            return false;
        else if((((arr[0]+arr[2]+arr[4]+arr[6]+arr[8])*7)-(arr[1]+arr[3]+arr[5]+arr[7]))%10!=arr[9])
            return false;
        else return (((arr[0]+arr[2]+arr[4]+arr[6]+arr[8])*8)%10 == arr[10]);
    }    
    protected int[] TCkontrollugenerate()
    {
        Rastgele random= new Rastgele();
        
        for(int i=0;i<TCdigit;i++)
        {
        TCno[i]=random.uretimRastgeleRakam(10);//önce hepsi rastgele rakamlardan oluşur
        }
        
        while(TCno[0]==0) //ilk rakam 0 dan farklı olmalıdır
            TCno[0]=random.uretimRastgeleRakam(10);
        
        TCno[9]=((((TCno[0]+TCno[2]+TCno[4]+TCno[6]+TCno[8])*7)-(TCno[1]+TCno[3]+TCno[5]+TCno[7]))%10);//10. basamak kuralı
        
        while((((TCno[0]+TCno[1]+TCno[2]+TCno[3]+TCno[4]+TCno[5]+TCno[6]+TCno[7]+TCno[8]+TCno[9])%10)!=TCno[10])||(((TCno[0]+TCno[2]+TCno[4]+TCno[6]+TCno[8])*8)%10!=TCno[10]))
            TCno[10]=random.uretimRastgeleRakam(10);//11. basamak kurala uyana kadar dene
        
        return TCno;//tc array döner
    }
}
