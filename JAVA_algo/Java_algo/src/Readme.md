# JAVA
## IO에 관한 지식
Java의 IO는 크게 Scanner와 BufferedReader가 있다
### Scanner
`import java.util.Scanner`  
예시)  
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
### BufferedReader
`import java.io.BufferedReader;`  
`import java.io.BufferedWriter;`  
`import java.io.IOException;`  
`import java.io.InputStreamReader;`  
`import java.io.OutputStreamWriter;`    
예시)  
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