using System;
using System.Collections;
using System.Collections.Generic;
using System.IO.Ports;
using NUnit.Framework.Internal;
using Unity.VisualScripting;
using UnityEngine;
using UnityEngine.Rendering;
using UnityEngine.SceneManagement;
using static UnityEditor.Progress;


public class InputHandler : MonoBehaviour
{

    [SerializeField]
    CarHandler carHandler;


    //Refs: https://discussions.unity.com/t/unity-is-giving-error-invalidoperationexception-specified-port-is-not-open/913855 
    //https://www.reddit.com/r/Unity3D/comments/1aunife/serial_port_ist_opened_but_no_data_can_be_read/
    //public float variable = 10;


    SerialPort Serial = new SerialPort("COM10", 9600);

    //public string reStr;
    //public Rigidbody2D rb;
    //public string[] data;


    //Remember this is how we know we're sending data to the microcontroller board when we input A or B, s
    bool rxFlag = false; // flag to indicate when new data has been received
    bool firstContact = false; // flag to indicate when the first contact has been made with the serial port

    //Sensors = Buttons and Potentiometer
    //Index Sensors[] = [0, 0, 0, 0]; // declare array to hold incoming sensor data, and initialize with zeros
    float[] buttonSensors = { 0, 0, 0, 0 };


    int pot1 = 0; // variable to hold potentiometer value
    int button1 = 0; // variable to hold 1st button value
    int button2 = 0; // variable to hold 2nd button value
    int button3 = 0; // variable to hold 3rd button value



    // Start is called once before the first execution of Update after the MonoBehaviour is created
    void Start()
    {


        SerialPort.GetPortNames();

        Serial.Open();
        Serial.ReadTimeout = 100;


        //if (!SerialPort.IsOpen)
        //{
        //    Serial.Open();
        //    //SerialPort.Open();
        //}



        
        Debug.Log(rxFlag); //Are we able to send data to the ESP32 Dev module with unity? 


    }

    // Update is called once per frame
    void Update()
    {

        //Player Input
        Vector2 input = Vector2.zero;


        //string data = Serial.ReadLine();
        //int value = int.Parse(data);

        //transform.rotation = Quaternion.Euler(0, value * 360/1023, 0);


        //foreach (string str in SerialPort.GetPortNames())
        //{
        //    Debug.Log(string.Format("Existing COM port: {0}", str));
        //}
        //reStr = Serial.ReadLine();

        //string[] data = reStr.Split(",");


        //rb.transform.position = new Vector3(rb.transform.position.x + float.Parse(data[0]) * Time.deltaTime, rb.transform.position.x + float.Parse(data[1]) * Time.deltaTime, 0);




        input.x = Input.GetAxis("Horizontal");
        input.y = Input.GetAxis("Vertical");

        carHandler.SetInput(input);

        if (Input.GetKeyDown(KeyCode.R))
        {
            SceneManager.LoadScene(SceneManager.GetActiveScene().name);
        
        
        }




    }


    //// Invoked when a line of data is received from the serial device.
    //void OnMessageArrived(string msg)
    //{
    //    Debug.Log("Arrived: " + msg);

    //}


    //// Invoked when a connect/disconnect event occurs. The parameter 'success'
    //// will be 'true' upon connection, and 'false' upon disconnection or
    //// failure to connect.
    //void OnConnectionEvent(bool success)
    //{
    //    Debug.Log(success ? "Device connected" : "Device disconnected");

    //}

    void OnMessageArrived(string msg)
    {
        Debug.Log("Arrived: " + msg);

    }


    // Invoked when a connect/disconnect event occurs. The parameter 'success'
    // will be 'true' upon connection, and 'false' upon disconnection or
    // failure to connect.
    void OnConnectionEvent(bool success)
    {
        Debug.Log(success ? "Device connected" : "Device disconnected");

    }


    private void OnApplicationQuit()
    {
        Serial.Close();

    }

    public void turnOn()
    {

        Serial.Write("1");


    }


    public void turnOff()
    {

        Serial.Write("0");


    }






}









