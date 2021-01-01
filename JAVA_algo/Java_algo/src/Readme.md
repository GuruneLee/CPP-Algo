# JAVA
## IO에 관한 지식
Java의 IO는 크게 Scanner와 BufferedReader가 있다
### Scanner
`import java.util.Scanner`    
ex)  
~~~  
Scanner sc = new Scanner(System.in);  
int integerNum = sc.nextInt();  
long longNum = sc.nextLong();  
double doubleNum = sc.nextDouble();  
String str = sc.next();  
String strWithSpace = sc.nextLine();  
// 등등...
sc.close();  
~~~  
  
**next()와 nextLine()의 차이**
ex) Scanner s = new Scanner("\n\n\n가나다\n\n라\n\n");  
~~~
//1. next(): 첫 단어 앞쪽 공백이나 개행문자는 무시. 하나의 단어를 입력받고, **단어 뒤의 개행문자는 그대로 놔둠**  
while(s.hasNext()) {
	str = s.next();
	System.out.println(str);
}
~~~
출력:  
가나다
라    
~~~
//2. nextLine(): **\n까지를 한 줄로 인식하고 입력**을 받고, \n은 버려진다. 
while(s.hasNext()) {
	str = s.nextLine();
	System.out.println(str);
}
~~~
출력:  
\n  
\n  
\n  
가나다  
\n  
라      


### BufferedReader
`import java.io.BufferedReader;`  
`import java.io.BufferedWriter;`  
`import java.io.IOException;`  
`import java.io.InputStreamReader;`  
`import java.io.OutputStreamWriter;`      
ex)  
~~~  
InputStreamReader isr = new InputStreamReader(System.in);
BufferedReader br = new BufferedReader(isr);

OutputStreamWriter osw = new OutputStreamWriter(System.out);
BufferedWriter bw = new BufferedWriter(osw);

try {

    // 입력
    String line = br.readLine();

    // 출력
    bw.write(line);
    bw.flush();
    bw.close();
} catch (IOException e) {
    e.printStackTrace();
}  
~~~   
  
`InputStreamReader`는 입력을 character로 읽어들임.  
`BufferedReader`는 InputStreasmReader에 버퍼링 기능 추가한 것. 버퍼에 보관했다가, 사용자가 원할때, 읽어오게 한다.  
BufferedReader는 throws Exception을 선언해 줘야 에러 없이 사용가능하기 때문에, Scanner보다 손이 훨씬 많이 가지만, **속도가 훨씬 빠르다**  

