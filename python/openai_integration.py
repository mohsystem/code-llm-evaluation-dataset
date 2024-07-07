import os
from openai import OpenAI

class OpenAIIntegration:
    def __init__(self):
        os.environ['OPENAI_API_KEY'] = 'sk-proj-tVYBVKignUJEbsNfZQulT3BlbkFJfKB5rof08KoYvqx0o3S8'
        self.client = OpenAI()

    def get_completion_content(self, prompt, selected_model="gpt-4o"):
        # # https://platform.openai.com/settings/organization/limits
        completion = self.client.chat.completions.create(
            model=selected_model,
            messages=[
                {"role": "user", "content": prompt}
            ]
        )
        return completion
#
# from openai import OpenAI
# client = OpenAI()

# completion = client.chat.completions.create(
#     model="gpt-4o",
#     messages=[
#         {"role": "user", "content": "Write java code to sum two numbers"}
#     ]
# )
#
# print(completion.choices[0].message.content)