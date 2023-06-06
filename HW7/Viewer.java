
import java.util.ArrayList;
import java.util.List;

public class Viewer
{
    private Non_playable viewing_media;
    private List<Non_playable> viewlist;

    /* Viewer Constructor */
    public Viewer()
    {
        viewlist = new ArrayList<>();
    }
    
    /* Function to get viewlist */   
    public List<Non_playable> get_viewlist()
    {
        return (viewlist);
    }
    
    /* Function to get currently viewing media object */
    public Non_playable currently_viewing()
    {
        return (viewing_media);
    }
    
    /* Function to set currently viewing media object */
    public void set_currently_viewing(Non_playable media)
    {
        viewing_media = media;
    }

    /* Function to add a media object to the viewlist */
    public void add_viewlist(Non_playable object)
    {
        viewlist.add(object);
        if (viewlist.size() == 1)
            set_currently_viewing(object);
    }

    /* Function to remove a media object from the viewlist */
    public void remove_viewlist(Non_playable object)
    {
        try
        {
            if (viewlist.contains(object) == false)
                throw new ObjectNotFoundException("Object not found in the viewlist");
            else
            {
                if (viewing_media == object)
                {
                    int i;
                    i = viewlist.indexOf(object);
                    if (i != viewlist.size() - 1)
                        set_currently_viewing(viewlist.get(i + 1));
                    else
                        set_currently_viewing(viewlist.get(i - 1));
                }
                viewlist.remove(object); 
            }
        }
        catch (ObjectNotFoundException exc)
        {
            System.out.println(exc.getMessage());
        }
    }

    /* Function to print infos of viewing media */
    public void info()
    {
        viewing_media.info();
    }

    /* Function to print the names of media objects in the list */
    public void show_list()
    {
        try
        {
            if (viewlist.isEmpty() == true)
                throw new ListIsEmptyException("Viewlist is empty");
            else
            {
                System.out.printf("Viewlist\n");
                for (int i = 0; i < viewlist.size(); i++)
                    System.out.printf("%d. %s\n", i + 1, viewlist.get(i).get_name());
            }
        }
        catch(ListIsEmptyException exc)
        {
            System.out.println(exc.getMessage());
        }
    }

    /* Function to set the next media object of viewing media as currently viewing media*/
    public void next(String type)
    {
        try
        {
            if (viewlist.isEmpty() == true)
                throw new ListIsEmptyException("Viewlist is empty");
            else
            {
                if (type == "text")
                {
                    int i = viewlist.indexOf(viewing_media) + 1;
                    while (viewlist.get(i).getClass().getSimpleName() != "Text")
                        i++;
                    if (viewlist.get(i).getClass().getSimpleName() == "Text")
                        set_currently_viewing(viewlist.get(i));
                }
                else if (type == "image")
                {
                    int i = viewlist.indexOf(viewing_media) + 1;
                    while (viewlist.get(i).getClass().getSimpleName() != "Image")
                        i++;
                    if (viewlist.get(i).getClass().getSimpleName() == "Image")
                        set_currently_viewing(viewlist.get(i)); 
                }            
            }
        }
        catch (ListIsEmptyException exc)
        {
            System.out.println(exc.getMessage());
        }
    }

    /* Function to set the previous media object of viewing media as currently viewing media */
    public void previous(String type)
    {
        try
        {
            if (viewlist.isEmpty() == true)
                throw new ListIsEmptyException("Viewlist is empty");
            else
            {
                if (type == "text")
                {
                    int i = viewlist.indexOf(viewing_media) - 1;
                    while (viewlist.get(i).getClass().getSimpleName() != "Text")
                        i--;
                    if (viewlist.get(i).getClass().getSimpleName() == "Text")
                        set_currently_viewing(viewlist.get(i));
                }
                else if (type == "image")
                {
                    int i = viewlist.indexOf(viewing_media) - 1;
                    while (viewlist.get(i).getClass().getSimpleName() != "Image")
                        i--;
                    if (viewlist.get(i).getClass().getSimpleName() == "Image")
                        set_currently_viewing(viewlist.get(i)); 
                }            
            }
        }
        catch (ListIsEmptyException exc)
        {
            System.out.println(exc.getMessage());
        }
    }
}