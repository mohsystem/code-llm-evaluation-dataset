package edu.bzu;

import org.everit.json.schema.Schema;
import org.everit.json.schema.loader.SchemaLoader;
import org.json.JSONObject;
import org.json.JSONTokener;

import java.io.FileInputStream;
import java.io.IOException;
import java.io.InputStream;

public class PromptDescriptionValidator {

    public static void main(String[] args) {
        InputStream jsonStream = null;
        InputStream schemaStream = null;
        try {
            // Load the JSON schema
            schemaStream = new FileInputStream("promptDescription/promptDescriptionSchema.json");
            JSONObject rawSchema = new JSONObject(new JSONTokener(schemaStream));
            Schema schema = SchemaLoader.load(rawSchema);

            jsonStream = new FileInputStream("promptDescription/promptDescriptionTemplate.json");
            JSONObject jsonToValidate = new JSONObject(new JSONTokener(jsonStream));

            schema.validate(jsonToValidate);
            System.out.println("JSON is valid against the schema.");
        } catch (Exception e) {
            System.out.println("JSON validation failed: " + e.getMessage());
        } finally {
            if (jsonStream != null) {
                try {
                    jsonStream.close();
                } catch (IOException e) {
                    e.getMessage();
                }
            }
            if (schemaStream != null) {
                try {
                    schemaStream.close();
                } catch (IOException e) {
                    e.getMessage();
                }
            }
        }
    }
}
