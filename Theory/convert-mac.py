import os
import subprocess

def convert_with_libreoffice(input_folder, output_folder):
    if not os.path.exists(output_folder):
        os.makedirs(output_folder)

    for file in os.listdir(input_folder):
        if file.endswith(".pptx"):
            input_path = os.path.join(input_folder, file)
            subprocess.run([
                "/Applications/LibreOffice.app/Contents/MacOS/soffice",
                "--headless", "--convert-to", "pdf",
                "--outdir", output_folder, input_path
            ])

convert_with_libreoffice(
    "/Users/shuvo/Documents/CSE105/CSE 105 Rakin Sir Slides",
    "/Users/shuvo/Documents/CSE105/CSE 105 Rakin Sir Slides"
)