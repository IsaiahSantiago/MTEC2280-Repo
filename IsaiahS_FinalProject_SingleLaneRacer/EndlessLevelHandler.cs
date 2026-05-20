using UnityEngine;
using System.Collections;
using System.IO.Ports;
using System.Collections.Generic;



public class EndlessLevelHandler : MonoBehaviour
{

    [SerializeField]
    GameObject[] sectionsPrefabs;

    //Will store all of our prefabs and ready to use per call
    GameObject[] sectionsPool = new GameObject[6];

    //Select from prefab objects available in the pool and render them
    GameObject[] sections = new GameObject[3];


    Transform playerCarTransform;

    //Running the prefabs overtime by creating them once and reusing them instead of making more and more
    WaitForSeconds waitFor100ms = new WaitForSeconds(0.3f);

    //So we can stack the sections in the array one after the other
    const float sectionLength = 13;




    void Start()
    {

        playerCarTransform = GameObject.FindGameObjectWithTag("Player").transform;

        int prefabIndex = 0;


        //Create a pool for our endless sections
        for (int i = 0; i < sectionsPool.Length; i++) //Iterating through out sections
        {
            sectionsPool[i] = Instantiate(sectionsPrefabs[prefabIndex]);
            sectionsPool[i].SetActive(false);

            prefabIndex++;


            //Loop the prefab index if we run out of prefabs to use
            if (prefabIndex > sectionsPrefabs.Length - 2)
            {
                prefabIndex = 0;
            }



        }



        //add the first sectrions to the road
        for (int i = 0; i < sections.Length; i++)
        {

        //get a random section:
        GameObject randomSection = GetRandomSectionFromPool();

        //Move it into position and set it to active
        randomSection.transform.position = new Vector3(sectionsPool[i].transform.position.x, 0, i * sectionLength);
        randomSection.SetActive(true);

        //set the section in the array
        sections[i] = randomSection;


        }


        StartCoroutine(UpdateLessOftenCO());

    }



    //Coroutine to update the sections positions every 100ms
    IEnumerator UpdateLessOftenCO()
    {
        while (true)
        {
            UpdateSectionsPositions();
            yield return waitFor100ms;


        }
    
    
    }

    void UpdateSectionsPositions()
    {

        for (int i = 0; i < sections.Length; i++)
        {

            //check if section is too far behind
            if (sections[i].transform.position.z - playerCarTransform.position.z < -sectionLength)
            {

                //store the position of the section and disable it
                Vector3 lastSectionPosition = sections[i].transform.position;
                sections[i].SetActive(false);


                //get new section and enable it & move it forward
                sections[i] = GetRandomSectionFromPool();

                //Move the new section into place and activate it
                sections[i].transform.position = new Vector3(lastSectionPosition.x, 0, lastSectionPosition.z + sectionLength * sections.Length);
                sections[i].SetActive(true);

            
            
            }

        
        
        }
    
    }


    GameObject GetRandomSectionFromPool()
    {

        //Pick a random index and hope that it is available
        int randomIndex = Random.Range(0, sectionsPool.Length);

        bool isNewSectionFound = false;

        while (!isNewSectionFound)
            {

            //Check if the sectino is Not active. In case we've found a section
            if (!sectionsPool[randomIndex].activeInHierarchy)
            {
                isNewSectionFound = true;

            }
            else
            {
                //If it was active we need to try to find another one so we increase the index
                randomIndex++;

                //Ensure that we loop if we reach hteh end of the Array
                if (randomIndex > sectionsPool.Length - 2)
                {
                    randomIndex = 0;



                }


            }




        }

        return sectionsPool[randomIndex];

    }




    //void Update()
    //{


    //}



















}












