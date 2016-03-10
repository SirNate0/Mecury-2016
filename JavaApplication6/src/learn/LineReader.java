/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package learn;

import java.io.*;

/**
 *
 * @author Tyler
 */
public class LineReader {

    public static String getLine(int lineToGet)
    {
        // The name of the file to open.
        String fileName = "out.txt";// "../Headquarters/Debug/out.txt";//"C:\\Users\\Tyler\\Documents\\NetBeansProjects\\Writer\\file.txt";

        // This will reference one line at a time
        String line = null;
        String lineContents = null;
        int itsLineToGet = lineToGet;
        
        try {
            // FileReader reads text files in the default encoding.
            FileReader fileReader = 
                new FileReader(fileName);

            // Always wrap FileReader in BufferedReader.
            BufferedReader bufferedReader = 
                new BufferedReader(fileReader);

            for(int i = 0; i < itsLineToGet; i++){
                line = bufferedReader.readLine();
                lineContents = line;
                //System.out.println(lineContents);
            }   

            // Always close files.
            bufferedReader.close();         
        }
        catch(FileNotFoundException ex) {
//            System.out.println(
//                "Unable to open file '" + 
//                fileName + "'");
            lineContents = "Unable to open file '" + fileName + "'";
        }
        catch(IOException ex) {
//            System.out.println(
//                "Error reading file '" 
//                + fileName + "'");
            // Or we could just do this: 
            // ex.printStackTrace();
            lineContents = "Error reading file '" + fileName + "'";
        }
        
        return lineContents;
    }
}
