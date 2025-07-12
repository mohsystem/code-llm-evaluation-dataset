# from mistralai.client import MistralClient
# from mistralai.models.chat_completion import ChatMessage
from mistralai import Mistral, UserMessage


class MistralIntegration:
    def __init__(self, model_name="codestral-latest"):  #model = "mistral-large-latest"

        # https://mistral.ai/technology/
        # https://docs.mistral.ai/getting-started/models/
        # https://docs.mistral.ai/api/#operation/createFIMCompletion
        # https://github.com/mistralai/client-python?tab=readme-ov-file
        # https://docs.mistral.ai/getting-started/clients/
        # https://console.mistral.ai/billing/

        self.api_key = "iWYGhriZX49bCPAeJdogLvYtDVgiBWwA"
        self.model = model_name
        # self.client = MistralClient(api_key=self.api_key)
        self.client = Mistral(api_key=self.api_key)
    def generate_content(self, prompt_desc):
        # chat_response = self.client.chat(
        #     model=self.model,
        #     messages=[ChatMessage(role="user", content=prompt_desc)]
        # )
        messages = [
            {
                "role": "user",
                "content": prompt_desc,
            },
        ]
        chat_response = self.client.chat.complete(
            max_tokens=4096,
            top_p=0.90,
            temperature=0.9,
            model=self.model,
            messages=messages,
        )

        # print(chat_response.choices[0].message.content)
        return chat_response.choices[0].message.content


    #https://github.com/mistralai/client-python/blob/speakeasy-sdk-regen-1724054966/MIGRATION.md

