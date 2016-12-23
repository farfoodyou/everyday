import java.io.InputStream;
import java.io.DataInputStream;
import java.io.InputStreamReader;
import java.io.OutputStream;
import java.io.DataOutputStream;
import java.io.BufferedReader;
import java.net.ServerSocket;
import java.net.Socket;
import java.io.IOException;
import java.util.Date;

class Server
{
public Server()
{
        try
        {
                ServerSocket s=new ServerSocket(8890);
                Socket ss=s.accept();
                OutputStream out=ss.getOutputStream();
                DataOutputStream dout=new DataOutputStream(out);
                InputStream in=ss.getInputStream();
                DataInputStream din=new DataInputStream(in);
                System.out.print(din.readUTF()+"!");
                dout.writeUTF("你已经连接到服务器"+"\t"+"你的地址："+ss.getInetAddress()+"\t"
                              +"你的链接端口："+ss.getLocalPort()+"\n");
                new ReadMessage(din).start();
                new SendMessage(dout).start();
        }
        catch (IOException e)
        {
                e.printStackTrace();
        }
}
public static void main(String[] args)
{
        new Server();
}
}

//接受客户端信息
class ReadMessage extends Thread
{
private DataInputStream din;

public ReadMessage(DataInputStream din)
{
        this.din=din;
}

public void run()
{
        String str;
        try
        {
                while (true)
                {
                        str=din.readUTF();
                        System.out.println(new Date().toLocaleString()+"客户端说："+str);
                        if (str.equals("bye"))
                        {
                                System.out.println("客户端下线！");
                                break;
                        }
                }
        }
        catch (IOException e)
        {
                e.printStackTrace();
        }
}
}

// 发出服务器信息
class SendMessage extends Thread
{
private DataOutputStream dout;

public SendMessage(DataOutputStream dout)
{
        this.dout=dout;
}

public void run()
{
        InputStreamReader inr=new InputStreamReader(System.in);
        BufferedReader buf=new BufferedReader(inr);
        String str;
        try
        {
                while(true)
                {
                        str=buf.readLine();
                        dout.writeUTF(str);
                        if (str.equals("bye"))
                        {
                                System.out.println("服务器退出！");
                                System.exit(1);
                        }
                }
        }
        catch (IOException e)
        {
                e.printStackTrace();
        }
}
}
