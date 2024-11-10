import java.awt.*;
import java.awt.event.*;

public class MainFrame extends Frame {

    public MainFrame() {
        setTitle("Choice and Button Example");
        setLayout(new FlowLayout());
        setSize(400, 200);

        Choice choice = new Choice();
        choice.setName("choiceComponent");
        choice.add("Java");
        choice.add("Python");
        choice.add("C++");
        choice.add("JavaScript");
        add(choice);

        choice.addItemListener(new ItemListener() {
            @Override
            public void itemStateChanged(ItemEvent e) {
                String selectedItem = choice.getSelectedItem();
                System.out.println("Selected item: " + selectedItem);
            }
        });

        Button openChildFrameButton = new Button("Open Child Frame");
        openChildFrameButton.setName("openChildFrameButton");
        add(openChildFrameButton);

        openChildFrameButton.addActionListener(new ActionListener() {
            @Override
            public void actionPerformed(ActionEvent e) {
                ChildFrame childFrame = new ChildFrame();
                childFrame.setVisible(true);
            }
        });

        addWindowListener(new WindowAdapter() {
            @Override
            public void windowClosing(WindowEvent we) {
                System.exit(0);
            }
        });
    }

    public static void main(String[] args) {
        MainFrame mainFrame = new MainFrame();
        mainFrame.setVisible(true);
    }
}

class ChildFrame extends Frame {

    public ChildFrame() {
        setTitle("Child Frame");
        setSize(300, 150);
        setLayout(new FlowLayout());

        Label label = new Label("This is a child frame.");
        label.setName("childFrameLabel");
        add(label);

        addWindowListener(new WindowAdapter() {
            @Override
            public void windowClosing(WindowEvent we) {
                setVisible(false);
            }
        });
    }
}
