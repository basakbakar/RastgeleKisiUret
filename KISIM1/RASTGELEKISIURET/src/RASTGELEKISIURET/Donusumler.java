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
public class Donusumler {
    public int[] StringToArrayInt(String str)
    {
        String[] splitArray = str.split("");//alınan string digitlerine ayrılır
        int[] array = new int[splitArray.length];//str uzunluğunda array oluşturulur
        for(int i=0;i<splitArray.length;i++)
        {
                try {
                    array[i] = Integer.parseInt(splitArray[i]);//her bir string digit i int e dönüştürülür
                } catch (NumberFormatException e) {
                    array[i]=-1;
                }
        }
        return array;
    }
    public String IntToString(int arr[],int size)
    {
        String str= new String();//heapte string oluşturulur
        for(int i=0;i<size;i++)
        {
            str+=Integer.toString(arr[i]);//array in her bir digit i string e eklenir
        }
        return str;
    }
}

