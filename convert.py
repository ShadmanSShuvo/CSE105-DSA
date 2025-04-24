import os
import comtypes.client

def pptx_to_pdf(input_folder, output_folder):
    if not os.path.exists(output_folder):
        os.makedirs(output_folder)

    powerpoint = comtypes.client.CreateObject("PowerPoint.Application")
    powerpoint.Visible = 1

    for filename in os.listdir(input_folder):
        if filename.endswith(".pptx"):
            full_path = os.path.join(input_folder, filename)
            output_file = os.path.join(output_folder, filename.replace(".pptx", ".pdf"))

            presentation = powerpoint.Presentations.Open(full_path)
            presentation.SaveAs(output_file, 32)  # 32 = PDF
            presentation.Close()

    powerpoint.Quit()

pptx_to_pdf("/Users/shuvo/Documents/CSE105/CSE 105 Rakin Sir Slides", "/Users/shuvo/Documents/CSE105/CSE 105 Rakin Sir Slides")
