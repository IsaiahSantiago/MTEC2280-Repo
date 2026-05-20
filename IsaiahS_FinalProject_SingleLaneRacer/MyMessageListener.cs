//using System.Collections;
//using System.IO.Ports;
//using System.Collections.Generic;
//using UnityEngine;
//using Unity.VisualScripting;


//public class MyMessageListener : MonoBehaviour
//{
//    //Ref https://discussions.unity.com/t/unity-is-giving-error-invalidoperationexception-specified-port-is-not-open/913855 

//    SerialPort Serial = new SerialPort("COM10", 9600);
//    public string reStr;
//    public Rigidbody2D rb;
//    public float speedyBoi = 10;
//    public string[] data;


//    // Use this for initialization
//    void Start()
//    {
//        Serial.Open();
         
//        Serial.ReadTimeout = 100;



//    }
//    // Update is called once per frame
//    void Update()
//    {

//        string data = Serial.ReadLine();
//        int value = int.Parse(data);


//        //foreach (string str in SerialPort.GetPortNames())
//        //{
//        //    Debug.Log(string.Format("Existing COM port: {0}", str));
//        //}
//        //reStr = Serial.ReadLine();

//        //string[] data = reStr.Split(",");


//        //rb.transform.position = new Vector3(rb.transform.position.x + float.Parse(data[0]) * Time.deltaTime, rb.transform.position.x + float.Parse(data[1]) * Time.deltaTime, 0);

//    }

//    // Invoked when a line of data is received from the serial device.
//    void OnMessageArrived(string msg)
//    {
//        Debug.Log("Arrived: " + msg);

//    }


//    // Invoked when a connect/disconnect event occurs. The parameter 'success'
//    // will be 'true' upon connection, and 'false' upon disconnection or
//    // failure to connect.
//    void OnConnectionEvent(bool success)
//    {
//        Debug.Log(success ? "Device connected" : "Device disconnected");

//    }




//    private void OnApplicationQuit()
//    {
//        Serial.Close();

//    }

//    public void turnOn()
//    {

//        Serial.Write("1");


//    }


//    public void turnOff()
//    {

//        Serial.Write("0");


//    }









//}











