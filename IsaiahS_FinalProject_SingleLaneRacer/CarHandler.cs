using UnityEngine;
using System.Collections;
using System.Collections.Generic;
using Unity.VisualScripting;


public class CarHandler : MonoBehaviour
{

    [SerializeField]
    Rigidbody rb;

    [SerializeField]
    Transform gameModel;

    //Max limiit values
    float maxSteerVelocity = 2;
    float maxForwardVelocity = 30;


    //Multipliers
    float accelerationMultiplier = 3;
    float breaksMultiplier = 15;
    float steeringMultiplier = 5;


    //Input
    Vector2 input = Vector2.zero;



    void Start()
    {


    }




    //We could add buttons in the update but an external script for that would be better for our Button mappings to the arduino
    void Update()
    {

        //rotate car model when "turning"
        gameModel.transform.rotation = Quaternion.Euler(0, rb.linearVelocity.x * 5, 0);

    }


    private void FixedUpdate()
    {
        //Applying acceleration
        if (input.y > 0)
        {
            Accelerate();

        }
        else
        {
            rb.linearDamping = 0.2f;

        }

        //Applying breaksS
        if (input.y < 0)
        {
            Break();

        }

        Steer();

        //prevents car from going backward
        if (rb.linearVelocity.z <= 0)
        {
            rb.linearVelocity = Vector2.zero;
        
        
        }


    }

    void Accelerate() //Meant for pushing the car "forward"
    {
        //rb.drag = 0;
        rb.linearDamping = 0;

        //Accelerate within the speed limit
        if (rb.linearVelocity.z >= maxForwardVelocity)
        {
            return;
        }

        rb.AddForce(rb.transform.forward * accelerationMultiplier * input.y); //Push of a button will increase car speed (Or Pot value for later)

        

    }


    void Break()
    {
        //Don't break unless we're moving forward and fast
        if (rb.linearVelocity.z <= 0 )
        {
            return;
        
        }

        rb.AddForce(rb.transform.forward * breaksMultiplier * input.y);



    }



    void Steer() //To control steering
    {
        if (Mathf.Abs(input.x) > 0)
        {

            //Moving the car sideways better
            float speedBasedSteerLimit = rb.linearVelocity.z / 5.0f;
            speedBasedSteerLimit = Mathf.Clamp01(speedBasedSteerLimit);


            //rb.AddForce(rb.transform.right * steeringMultiplier * input.y );
            rb.AddForce(rb.transform.right * steeringMultiplier * input.x * speedBasedSteerLimit);

            //Autocentering the car \ Normalizing the X velocity
            float normalizedX = rb.linearVelocity.x / maxSteerVelocity;

            //Making sure we don't go over -1 or 1 in magnitued
            normalizedX = Mathf.Clamp(normalizedX, -1.0f, 1.0f);


            //staying within the speed limit:
            rb.linearVelocity = new Vector3(normalizedX * maxSteerVelocity, 0, rb.linearVelocity.z);

        }

        else
        {
            //Stabalizing the car
            rb.linearVelocity = Vector3.Lerp(rb.linearVelocity, new Vector3(0, 0, rb.linearVelocity.z), Time.fixedDeltaTime * 3);

        }



        



    }


    public void SetInput(Vector2 inputVector)
    {

        inputVector.Normalize(); //check if input is between -1 or 1

        input = inputVector;



    }











}




























