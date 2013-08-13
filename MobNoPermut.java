import java.util.Scanner;

class MobNoPermut{
	
	static	String a1="abc",a2="def",a3="ghi",a4="jkl",a5="mno",a6="pqrs",a7="tuv",a8="wxyz";
		
		
	public static void main(String arg[])	
	{
		Scanner sc=new Scanner(System.in);
		String str=sc.nextLine();
		System.out.println(str);
		permut(str,"",str.length());
		sc.close();
	}
	static void permut(String str,String res,int len)
	{
		if(len==0)
		{
			System.out.println(res);
			System.out.print(" ");
			return;
		}
		String a="";
		switch(str.charAt(str.length()-len))
		{
			case '2':
			a=a1;
			break;
			case '3':
			a=a2;
			break;
			case '4':
			a=a3;
			break;
			case '5':
			a=a4;
			break;
			case '6':
			a=a5;
			break;
			case '7':
			a=a6;
			break;
			case '8':
			a=a7;
			break;
			case '9':
			a=a8;
			break;
		}
		for(int i=0;i<a.length();i++)
		{
			permut(str,res+String.valueOf(a.charAt(i)),len-1);
		}
		
	}
