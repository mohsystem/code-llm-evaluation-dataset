package edu.bzu.llm;

import io.github.stefanbratanov.jvm.openai.*;

public class ChatGPTIntegration {

    private static final String API_KEY = "sk-proj-tVYBVKignUJEbsNfZQulT3BlbkFJfKB5rof08KoYvqx0o3S8";

    public static void main(String[] args) {
        // Define the prompt
        String prompt = "Write me a code for binary search";

        // Send the request and handle the response
        try {
            OpenAI openAI = OpenAI.newBuilder(API_KEY).build();

            ChatClient chatClient = openAI.chatClient();
            CreateChatCompletionRequest createChatCompletionRequest = CreateChatCompletionRequest.newBuilder()
                    .model(OpenAIModel.GPT_3_5_TURBO)
                    .message(ChatMessage.userMessage(prompt))
                    .build();

            ChatCompletion chatCompletion = chatClient.createChatCompletion(createChatCompletionRequest);
            // Print the response
            System.out.println(chatCompletion.choices().get(0));
        } catch (Exception e) {
            e.printStackTrace();
        }
    }
}