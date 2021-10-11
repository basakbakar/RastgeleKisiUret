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
public class Telefon {
    private final int telDigit=12;//sabit digit hanesi sayısı
    private int telNo[]=new int [telDigit];
    private int[] hat={501, 505, 506, 507, 551, 552, 553, 554, 555, 559,530, 531, 532, 533, 534, 535, 536, 537, 538, 539, 561, 540, 541, 542, 543, 544, 545, 546, 547, 548, 549};
    //geçerli 31 hat array de tutulur
    protected int[] telNoOlustur()
    {
        Rastgele random= new Rastgele();//rastgele çağırılır
        int rastgeleHat=random.uretimRastgeleRakam(31);//mod 31 alınarak 0-30 arasında random dayı elde edilir hat seçmede kullanılır
        
        telNo[0]=9;telNo[1]=0;//TR kodu
        telNo[2]=hat[rastgeleHat]/100;
        telNo[3]=(hat[rastgeleHat]/10)%10;
        telNo[4]=hat[rastgeleHat]%10;
        //seçilen random hat basamaklara ayrılır
        for(int i=5;i<12;i++)
        {
            telNo[i]=random.uretimRastgeleRakam(10);//kurala bağlı olmayan haneler random ile rakam rakam üretilir
        }

        
        return telNo;//tel no array döner
    }
}
